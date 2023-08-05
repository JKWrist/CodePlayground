#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h> //read
#include <ctype.h>
#include <string.h>
#include <strings.h> // bzero
#include <arpa/inet.h> //htonl htons


typedef struct info
{
    int cfd;   //若为-1表示可用， 大于0表示已经被占用
    int idx;
    pthread_t thread;
    struct sockaddr_in client;
}INFO;

INFO thread_INFO[1024];


init_thread_INFO()
{
    for (int i = 0; i < 1024; i++)
    {
        thread_INFO[i].cfd = -1;
    }
}

int find_Index()
{
    int i = 0; 
    
    for (; i < 1024; i++)
    {
        if (-1 == thread_INFO[i].cfd)
        {
            break;
        }
    }
    if (1024 == i)
    {
        return -1;
    }

    return i;
}

//线程执行函数
void * thread_work(void * arg)
{
    INFO *p = (INFO *)arg;
    printf("idx = [%d]\n", p->idx);

    char sIP[16] = {0};
    memset(sIP, 0, sizeof(sIP));
    printf("new client:[%s][%d]\n", \
    inet_ntop(AF_INET, &(p->client.sin_addr.s_addr), sIP, sizeof(sIP)), htons(p->client.sin_port));

    int n;
    int cfd = p->cfd;
    char buf[1024] = {0};

    while (1)
    {
        memset(buf, 0, sizeof(buf));
        //读数据
        n = read(cfd, buf, sizeof(buf));
        if(n <= 0)
        {
            printf("read error or client closed n = %d\n", n);
            close(cfd);
            p->cfd = -1;
            pthread_exit(NULL);
        }

        for (int i = 0; i < n; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        write(cfd, buf, sizeof(buf));
    }
    
}


//多线程，高阶版本
/****************************************************************
 *  函数名称：
 *  创建日期：2021-11-29 20:15:18
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //创建socket
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    //设置端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    //绑定--将lfd和IP PORT绑定
    struct sockaddr_in serv;
    bzero(&serv, sizeof(serv));

    serv.sin_family = AF_INET;
    serv.sin_port = ntohs(8888);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    
    bind(lfd, (struct sockaddr*)&serv, sizeof(serv));

    listen(lfd, 128);

    //初始化
    init_thread_INFO();

    int cfd;
    int ret;
    int idx;
    socklen_t len;
    pthread_t thread;
    struct sockaddr_in client;

    while (1)
    {
        len = sizeof(client);
        bzero(&client, len);
        //获得一个新的连接
        cfd = accept(lfd, (struct sockaddr *)&client, &len);

        //创建一个子进程，让子进程处理连接---收发数据
        //找数组中空闲的位置
        idx = find_Index();
        if(-1 == idx)
        {
            close(cfd);
            continue;
        }

        //对空闲位置的元素成员赋值
        thread_INFO[idx].cfd = cfd;
        thread_INFO[idx].idx = idx;
        memcpy(&thread_INFO[idx].client, &client, sizeof(client));

        //创建时子线程--该子线程完成对数据的收发
        ret = pthread_create(&thread_INFO[idx].thread, NULL, thread_work, &thread_INFO[idx]);
        if (0 != ret)
        {
            printf("create thread error:[%s]\n", strerror(ret));
            exit(-1);
        }

        //设置子线程为分离属性
        pthread_detach(thread_INFO[idx].thread);
    }

    close(lfd);

    return 0;
}

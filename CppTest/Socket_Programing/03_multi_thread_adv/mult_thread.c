#include <stdio.h>
#include <stdlib.h>
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
    for (int i = 0; i < 1024; i++)
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
    setsockopt(lfd, SOL_SOCKET, SO_REUSERADDR, &opt, sizeof(int));

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


    return 0;
}

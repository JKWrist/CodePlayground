#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <netinet/in.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-30 09:17:35
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int ret;

    //创建socket
    int lfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (lfd < 0)
    {
        perror("socket error");
        return -1;
    }

    //accept error: Resource temporarily unavailable
    //这里如果使用非阻塞会报如上错误
    
    // int flags = fcntl(lfd, F_GETFL, 0);
    // flags = flags | O_NONBLOCK;
    // int ret = fcntl(lfd, F_SETFL, flags);
    // if(ret == -1)
    // {
    //     perror("fcntl error");
    // }

    //删除socket文件，避免bind失败
    unlink("./server.sock");

    //绑定bind
    struct sockaddr_un serv;
    bzero(&serv, sizeof(serv));
    serv.sun_family = AF_UNIX;
    strcpy(serv.sun_path, "./server.sock");
    ret = bind(lfd, (struct sockaddr *)&serv, sizeof(serv));
    if(ret < 0)
    {
        perror("bind error");
        return -1;
    }

    //监听listen
    listen(lfd, 10);

    //接收新的连接-accept
    struct sockaddr_un client;
    bzero(&client, sizeof(client));
    int len = sizeof(client);
    int cfd = accept(lfd, (struct sockaddr *)&client, &len);
    printf("%d %d %d\n", cfd, EWOULDBLOCK, EAGAIN);
    // if (cfd == EWOULDBLOCK || cfd == EAGAIN)
    // {
    //     continue;
    // }
    // else 
    if (cfd < 0)
    {
        perror("accept error");
        return 1;
    }
    printf("client->[%s]\n", client.sun_path);

    int n;
    char buf[1024];

    while (1)
    {
        //读数据
        memset(buf, 0, sizeof(buf));
        n = read(cfd, buf, sizeof(buf));
        if(n <= 0)
        {
            printf("readover or client close, n ==[%d]\n", n);
            break;
        }
        printf("n==[%d], buf==[%s]\n", n, buf);

        //发送数据
        write(cfd, buf, n);
    }
    close(lfd);
    
    return 0;
}

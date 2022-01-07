#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <arpa/inet.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-30 09:18:28
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //创建socket
    int cfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if(cfd < 0)
    {
        perror("socket error");
        return -1;
    }

    //删除socket文件，避免bind失败
    //如果不删除 bind error: Address already in use
    unlink("./client.sock");

    //绑定bind
    struct sockaddr_un client;
    bzero(&client, sizeof(client));
    client.sun_family = AF_UNIX;
    strcpy(client.sun_path, "./client.sock");
    int ret = bind(cfd, (struct sockaddr *)&client, sizeof(client));
    if(ret < 0)
    {
        perror("bind error");
        return -1;
    }

    struct sockaddr_un serv;
    bzero(&serv, sizeof(serv));
    serv.sun_family = AF_UNIX;
    strcpy(serv.sun_path, "./server.sock");
    ret = connect(cfd, (struct sockaddr *)&serv, sizeof(serv));

    if(ret < 0)
    {
        perror("connect error");
        return -1;
    }
    int n;
    char buf[1024] = {0};

    while (1)
    {
        memset(buf, 0, sizeof(buf));
        n = read(STDIN_FILENO, buf, sizeof(buf));
        printf("qqq\n");

        //发送数据
        write(cfd, buf, n);

        printf("111\n");

        //接收数据
        memset(buf, 0, sizeof(buf));
        n = read(cfd, buf, sizeof(buf));
        if(n <= 0)
        {
            printf("read error or client close, n==[%d]\n", n);
            break;
        }
        printf("read buf:[%s], n = %d\n", buf, n);
    }
    close(cfd);
}
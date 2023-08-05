#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-17 20:04:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //创建socket
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    if (lfd < 0)
    {
        perror("socket error");
        return -1;
    }

    //绑定
    struct sockaddr_in serv;
    bzero(&serv, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    
    //本地任意可用IP
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    int ret = bind(lfd, (struct sockaddr *)&serv, sizeof(serv));
    if (ret < 0)
    {
        perror("bind error");
        return -1;
    }

    listen(lfd, 128);

    struct sockaddr_in client;
    socklen_t len = sizeof(client);
    int cfd = accept(lfd, (struct sockaddr *)&client, &len);

    printf("accept %d\n", cfd);

    // const char *
    // inet_ntop(int af, const void *restrict src, char *restrict dst,
    //           socklen_t size);

    //获取client端的IP和端口
    char sIP[16];
    memset(sIP, 0, sizeof(sIP));
    printf("client IP:[%s], port:[%d]\n",
           inet_ntop(AF_INET, &client.sin_addr.s_addr, sIP, sizeof(sIP)),
           ntohs(client.sin_port));

    printf("lfd = [%d], cfd = [%d]\n", lfd, cfd);

    int i = 0;
    int n = 0;
    char buf[1024];
    while (1)
    {
        //读数据
        memset(buf, 0, sizeof(buf));
        n = read(cfd, buf, sizeof(buf));
        if (n <= 0)
        {
            printf("read error or client close, n == [%d]\n",n);
            break;
        }
        printf("server read n == [%d], buf == [%s]\n", n, buf);

        for (int i = 0; i < n; i++)
        {
           buf[i] = toupper(buf[i]);
        }
        
        //发送数据
        write(cfd, buf, n);
    }

    close(cfd);
    close(lfd);

    return 0;
}

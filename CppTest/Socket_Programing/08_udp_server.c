//udp客户端

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <ctype.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-01-04 20:12:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //创建socket
    int cfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (cfd < 0)
    {
        perror("socket error");
        return -1;
    }

    //绑定
    struct sockaddr_in serv;
    struct sockaddr_in client;
    bzero(&serv, sizeof(serv));
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(cfd, (struct sockaddr *)&serv, sizeof(serv));

    int i;
    int n;
    socklen_t len;
    char buf[1024];
    while (1)
    {
        //读取数据
        memset(buf, 0x00, sizeof(buf));
        len = sizeof(client);
        n = recvfrom(cfd, buf, sizeof(buf), 0, (struct sockaddr *)&client, &len);
        printf("[%d]\n", n);
        
        //将大写转换为小写
        for (i = 0; i < n; i++)
        {
            buf[i] = toupper(buf[i]);
        }
        printf("[%d]:n==[%d], buf==[%s]\n", ntohs(client.sin_port), len, buf);

        //发送数据
        sendto(cfd, buf, n, 0, (struct sockaddr *)&client, len);
    }

    //关闭套接字
    close(cfd);

    return 0;
}
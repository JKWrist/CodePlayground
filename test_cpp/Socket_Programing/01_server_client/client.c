#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <unistd.h>
/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-16 21:55:22
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //创建socket 
    int cfd = socket(AF_INET, SOCK_STREAM, 0);
    if(cfd < 0)
    {
        perror("socket error");
        return -1;
    }

    //连接服务器
    struct sockaddr_in serv;
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8888);
    inet_pton(AF_INET, "47.93.246.97", &serv.sin_addr.s_addr);
    printf("[%x]\n", serv.sin_addr.s_addr);
    
    int ret = connect(cfd, (struct sockaddr *)&serv, sizeof(serv));
    if(ret < 0)
    {
        perror("connect error");
        return -1;
    }

    int n = 0;
    char buf[256];
    
    while(1)
    {
        //读标准输入数据
        memset(buf, 0x00, sizeof(buf));
        n = read(STDIN_FILENO, buf, sizeof(buf));

        //发送数据
        write(cfd, buf, n);

        //读服务端发来的数据
        memset(buf, 0x00, sizeof(buf));
        n = read(cfd, buf, sizeof(buf));
        if( n <= 0)
        {
            printf("client read error or server closed, n == [%d]\n", n);
        }
        printf("n == [%d], buf == [%s]\n", n, buf);
    }

    close(cfd);

    return 0;
}

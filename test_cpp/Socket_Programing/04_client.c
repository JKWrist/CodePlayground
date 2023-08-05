#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-03 17:00:06
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    int sock;
    char message[BUF_SIZE] = {0};
    struct sockaddr_in serv_addr;
    const char hello[128] = "hello world";

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock < 0)
    {
        perror("socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    int ret = connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    
    if(ret < 0)
    {
        perror("connect");
    }

    while (1)
    {
        write(sock, hello, sizeof(hello));

        int str_len = read(sock, message, BUF_SIZE);
        printf("%s\n", message);
    }
    
    return 0;
}

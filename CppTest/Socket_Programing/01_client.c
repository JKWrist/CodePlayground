#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
    inet_pton(AF_INET, "127.0.0.1", serv.sin_addr.s_addr);
    printf("[%x]\n", serv.sin_addr.s_addr);
    
    int ret = conect(cfd, (struct sockadddr *)&serv, sizeof(serv));
    if(ret < 0)
    {
        perror("connect error");
        return -1;
    }

    int n = 0;
    char buf[256];
    
    while(1)
    {
        
    }

    return 0;
}

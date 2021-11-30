#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>  //ntohs ntohl htonl
#include <sys/select.h> //select
#include <sys/socket.h> //socket bind listen accept
#include <unistd.h>     //read
#include <strings.h>    //bzero
#include <ctype.h>     //toupper

//#include <time.h>

#define BUF_SIZE 100

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-30 21:25:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    int serv_sock, cli_sock;
    struct sockaddr_in serv_addr, cli_addr;
    struct timeval timeout;
    fd_set reads, copy_reads;

    socklen_t len;

    int fd_max;

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket %d\n", serv_sock);

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_family = AF_INET;

    bind(serv_sock, (struct sockaddr *)&serv_addr, len);

    listen(serv_sock, 256);

    FD_ZERO(&reads);
    FD_SET(serv_sock, &reads);
    fd_max = serv_sock;

    while (1)
    {
        printf("1111111111\n");
        copy_reads = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        int i = select(fd_max + 1, &copy_reads, 0, 0, &timeout);
        if (-1 == i)
        {
            break;
        }
        
        if (0 == i)
        {
            continue;
        }

        for(int i = 0; i < fd_max + 1; i++)
        {
            printf("222222222%d\n", i);

            if(FD_ISSET(i, &copy_reads))
            {
                if(serv_sock == i)   //connect sock
                {
                    len = sizeof(cli_addr);
                    cli_sock = accept(serv_sock, (struct sockaddr *)&cli_addr, &len);
                    FD_SET(cli_sock, &reads);
                    if(fd_max < cli_sock)
                        fd_max = cli_sock;
                    
                    printf("%d\n", cli_sock);
                }
                else          //read message
                {
                    char buf[BUF_SIZE] = {0};
                    int str_len = read(i, buf, sizeof(buf));
                    for (int i = 0; i < str_len; i++)
                    {
                        buf[i] = toupper(buf[i]);
                    }
                    write(i, buf, str_len);
                }

            }


        }
    }
    close(serv_sock);
    return 0;
}

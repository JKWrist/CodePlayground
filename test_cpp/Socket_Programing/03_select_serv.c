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

    //bzero(&serv_addr, sizeof(serv_addr));
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_family = AF_INET;

    int ret = bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    //int ret = bind(serv_sock, (struct sockaddr *)&serv_addr, len);
    //bind 出错原因是结构体变量传参为0，因为len在开始的时候没有赋值，就是0

    if(ret < 0)
        perror("bind error");

    ret = listen(serv_sock, 256);
    if (ret < 0)
        perror("listen error");

    FD_ZERO(&reads);
    FD_SET(serv_sock, &reads);
    fd_max = serv_sock;

    while (1)
    {
        sleep(1);
        copy_reads = reads;
        timeout.tv_sec = 5;
        timeout.tv_usec = 0;
        int ret = select(fd_max + 1, &copy_reads, 0, 0, &timeout);
        printf("select return %d\n", ret);

        if (-1 == ret)
        {
            break;
        }

        if (0 == ret)
        {
            continue;
        }

        for(int i = 0; i < fd_max + 1; i++)
        {
            if(FD_ISSET(i, &copy_reads))
            {
                if(serv_sock == i)   //connect sock
                {
                    len = sizeof(cli_addr);
                    cli_sock = accept(serv_sock, (struct sockaddr *)&cli_addr, &len);
                    FD_SET(cli_sock, &reads);
                    if(fd_max < cli_sock)
                        fd_max = cli_sock;

                    printf("listen cli_sock %d\n", cli_sock);
                }
                else          //read message
                {
                    char buf[BUF_SIZE] = {0};
                    int str_len = read(i, buf, sizeof(buf));
                    
                    //下面的这个if非常重要
                    //没有数据就可以将连接关掉，并且从select监听中去除
                    if (0 == str_len) // close request!
                    {
                        FD_CLR(i, &reads);
                        close(i);
                        printf("closed client: %d \n", i);
                    }

                    printf("read data from [%d] [%s]\n", i, buf);
                    
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

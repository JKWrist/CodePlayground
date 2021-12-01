#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

#include <poll.h>  //poll
#include <ctypes.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_LENGTH 80
#define OPEN_MAX 1024

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-01 20:50:19
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    int i, j, maxi, listenfd, confd, sockfd;
    socklen_t cli_len;

    struct pollfd client[OPEN_MAX];
    struct sockaddr_in cli_addr, serv_addr;

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(listenfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    listen(listenfd, 128);

    client[0].fd = listenfd;

    /*listenfd监听普通读事件, 那么对于监听文件描述符来说就是连接请求到来*/
    client[0].events = POLLIN;

    for (int i = 1; i < OPEN_MAX; i++)
    {
        client[i].fd = -1;
    }
    maxi = 0;

    while (1)
    {
        //检测client[]
        int nready = poll(client, maxi + 1, -1);
        if (client[0].revents & POLLIN)
        {
            //客户端请求到来
            cli_len = sizeof(cli_addr);
            char IP[16] = {0};
            confd = accept(listenfd, (struct sockaddr *)&cli_addr, &cli_len);
            printf("received from [%s] at port [%d]\n", \
                inet_ntop(AF_INET, &cli_addr.sin_addr, IP, sizeof(IP)),\
                ntohs(cli_addr.sin_port));
            
            for (int i = 0; i < OPEN_MAX; i++)
            {
                if(client[i].fd < 0)
                {
                    client[i].fd = connfd;
                    break;
                }
            }

            if (OPEN_MAX == i)
            {
               printf("too many clients\n");
            }
            
            client[i].events = POLLIN;
            //设置刚刚返回的connfd，监控读事件
            
            if(i > maxi)
            {
                //更新client中最大的元素下标
                maxi = i;
            }

            if(--nready <= 0)
            {
                //没有更多就绪事件时，继续回到poll阻塞
                continue;
            }
        }

        char buf[BUF_LENGTH];

        for (int i = 1; i < maxi; i++)
        {
            //检测clinet[]接收数据
            if((sockfd = client[i].fd) < 0)
            {
                continue;
            }

            if (POLLIN == client[i].revents)
            {
                if((n = read(sockfd, buf, sizeof(buf))) < 0)
                {
                    if(errno == ECONNRESET)
                    {
                        //connection reset by client
                        printf("client[%d] aborted connection\n", i);
                        close(sockfd);
                        client[i].fd = -1;
                    }
                    else
                    {
                        perror("read error");
                    }
                }
                else if(0 == n)
                {
                    //connection closed by client
                    printf("client[%d] closed connection\n");
                    close(sockfd);
                    client[i].fd =-1;
                }
                else
                {
                    for(int j = 0; j < n; j++)
                    {
                        buf[j] = toupper(buf[j]);
                    }
                    write(sockfd, buf, n);
                }
                
                if(--nready <= 0)
                {
                    break;
                }
            }
        }
        
    }
    return 0;
}

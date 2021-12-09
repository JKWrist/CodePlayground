#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <error.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/epoll.h>

#define BUF_SIZE 4
#define EPOLL_SIZE 50
/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-07 21:36:41
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    int serv_sock, clnt_sock;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t adr_sz;

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);

    int flag = fcntl(serv_sock, F_GETFL, 0);
    fcntl(serv_sock, F_SETFL, flag | O_NONBLOCK);

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_family = AF_INET;
    int ret = bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if(-1 == ret)
    {
        printf("bind() error\n");
    }

    listen(serv_sock, 128);
    
    int epfd, event_cnt;
    epfd = epoll_create(EPOLL_SIZE);

    struct epoll_event *ep_events = malloc(EPOLL_SIZE * sizeof(struct epoll_event));
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = serv_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

    while (1)
    {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if(-1 == event_cnt)
        {
           printf("epoll_wait error \n");
           exit(1);
        }

        for (int i = 0; i < event_cnt; i++)
        {
            if (serv_sock == ep_events[i].data.fd)
            {
                socklen_t len;
                //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
                clnt_sock = accept(serv_sock, (struct sockaddr*)&cli_addr, &len);
                printf("clnt_sock = [%d]\n", clnt_sock);
                event.events = EPOLLIN | EPOLLET;
                event.data.fd = clnt_sock;
                epoll_ctl(epfd, EPOLL_CTL_ADD, clnt_sock , & event);
            }
            else
            {
                //传输数据
                int sock = ep_events[i].data.fd;
                char buf[4] = {0};
                int read_len = read(sock, buf, sizeof(buf));
                printf("read_len = [%d]\n", read_len);
                if (0 == read_len)
                {
                    epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                    close(sock);
                    printf("close socket [%d]\n", sock);
                }
                else
                {
                    write(sock, "echo!", sizeof("echo!"));
                }
            }

        }
    }

    close(serv_sock);
    close(epfd);
    
    return 0;
}

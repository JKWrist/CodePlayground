#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
//#include <sys/types.h>
#include <sys/epoll.h>
#include <arpa/inet.h>

#define BUF_SIZE 1024
#define EPOLL_SIZE 50
/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-08 18:54:24
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    int serv_sock, cli_sock;
    struct sockaddr_in serv_addr, cli_addr;

    serv_sock = socket(AF_INET, SOCK_STREAM, 0);
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(8888);
    serv_addr.sin_family = AF_INET;
    
    int flag = fcntl(serv_sock, F_GETFL, 0);
    fcntl(serv_sock, F_SETFL, flag|O_NONBLOCK);

    int ret = bind(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if(-1 == ret)
    {
        printf("bind error\n");
    }
    
    listen(serv_sock, 128);

    struct epoll_event *ep_events;
    struct epoll_event event;
    int epfd, event_cnt;

    epfd = epoll_create(EPOLL_SIZE);
    
    ep_events = malloc(sizeof(struct epoll_event) * EPOLL_SIZE);
    event.events = EPOLLIN;
    event.data.fd = serv_sock;
    epoll_ctl(epfd, EPOLL_CTL_ADD, serv_sock, &event);

    while (1)
    {
        event_cnt = epoll_wait(epfd, ep_events, EPOLL_SIZE, -1);
        if(-1 == event_cnt)
        {
            puts("epoll_wait() serror");
            break;
        }

        for (int i = 0; i < event_cnt; i++)
        {
            if(serv_sock == ep_events[i].data.fd)
            {
                socklen_t addr_sz;
                addr_sz = sizeof(cli_addr);
                cli_sock = accept(serv_sock, (struct sockaddr*)&cli_addr, &addr_sz);
                //将传输文件描述符上树，方便内核进行监听
                event.events = EPOLLIN;
                event.data.fd = cli_sock;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cli_sock, &event);
                printf("connect client : %d\n", cli_sock);
            }
            else
            {
                int str_len;
                char buf[BUF_SIZE] = {0};
                //char buf[BUF_SIZE];  //尝试不将数据清空会有什么事情发生
                str_len = read(ep_events[i].data.fd, buf, sizeof(buf));
                printf("read length : [%d] read data : [%s]\n", str_len, buf);
                if(0 == str_len)
                {
                    epoll_ctl(epfd, EPOLL_CTL_DEL, ep_events[i].data.fd, NULL);
                    close(ep_events[i].data.fd);
                    printf("close client : [%d]\n", ep_events[i].data.fd);
                }
                else
                {
                    write(ep_events[i].data.fd, buf, str_len);
                }
            }
        }
    }
    
    close(serv_sock);
    close(epfd);
    return 0;
}

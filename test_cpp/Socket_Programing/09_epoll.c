//EPOLL模型测试
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-01-12 18:14:25
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    int ret;
    int lfd, cfd;
    char buf[1024] = {0};
    socklen_t socklen;
    struct sockaddr_in servaddr;

    //创建socket
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    
    //设置文件描述符为端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    //绑定bind
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8888);
    bind(lfd, (struct sockaddr*)&servaddr, sizeof(struct sockaddr_in));

    //监听listen
    listen(lfd, 120);

    //创建epoll树
    int epfd = epoll_create(1024);
    if(epfd < 0)
    {
        perror("epoll_create error");
        close(lfd);
        return -1;
    }

    //将lfd上eppll树
    //int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event);
    struct epoll_event ev;
    ev.data.fd = lfd;
    ev.events = EPOLLIN;
    epoll_ctl(epfd, EPOLL_CTL_ADD, lfd, &ev);

    int nready;
    struct epoll_event events[1024];

    //阻塞等待事件的发生
    while(1)
    {
        // int epoll_wait(int epfd, struct epoll_event *events,
        //               int maxevents, int timeout);

        nready = epoll_wait(epfd, events, 1024, -1);
        if( nready < 0)
        {
            perror("epoll_wait error");
            if(EINTR == errno)
            {
                continue;
            }
            exit(1);
        }

        for(int i = 0; i < nready; i++)
        {
            int sockfd = events[i].data.fd;
            //客户端连接请求
            if(sockfd == lfd)
            {
                cfd = accept(sockfd, NULL, NULL);
                printf("new client fd :[%d]\n", cfd);
                
                //将新的通信文件描述符上树
                ev.data.fd = cfd;
                ev.events = EPOLLIN;
                epoll_ctl(epfd, EPOLL_CTL_ADD, cfd, &ev);
                continue;
            }

            //下面是数据发来的情况
            int n;
            memset(buf, 0x00, sizeof(buf));
            n = read(sockfd, buf, sizeof(buf));
            if(n <= 0)
            {
                printf("read error or client closed, n == [%d]\n", n);
                close(sockfd);
                //将sockfd对应的时间下树
                epoll_ctl(epfd, EPOLL_CTL_DEL, sockfd, NULL);
            }
            else
            {
                printf("read over, n == [%d], buf = [%s]\n", n, buf);
                write(sockfd, buf, n);
            }
        }
    }

    //关闭文件根节点和监听文件描述符
    close(epfd);
    close(lfd);

    return 0;
}

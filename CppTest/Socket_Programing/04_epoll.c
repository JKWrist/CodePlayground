//EPOLL模型测试
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <sys/socket.h>

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
    int n;
    int lfd, cfd, sockfd;
    char buf[1024] = {0};
    socklen_t socklen;
    struct sockaddr_in servaddr;
    struct epoll_event ev;
    struct epoll_event events[1024];

    //创建socket
    lfd = socket(AF_INET, SOCK_STREAM, 0);
    
    //设置文件描述符为端口复用
    int opt = 1;
    setsocketopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    //绑定bind
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr_s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(8888);
    bind(lfd, (struct sockaddr*)&servaddr, sizeof(struct sockaddr_in));

    //监听listen
    listen(lfd, 120);

    //创建epoll树
    int epfd = epoll_create(1024);

    return 0;
}

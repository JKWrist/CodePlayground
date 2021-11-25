//多进程版本的服务器
#include <stdio.h>
#include <string.h>
#include <strings.h> //bzero
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> //pid_t
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#include <sys/socket.h> //setsockopt  accept
#include <sys/wait.h>
#include <arpa/inet.h> //htons
#include <netinet/in.h>

//信号处理函数
void waitchild(int signo)
{
    pid_t wpid;
    while (1)
    {
        wpid = waitpid(-1, NULL, WNOHANG);
        if (wpid > 0)
        {
            printf("child exit, wpid = [%d]\n", wpid);
        }
        else if (0 == wpid || wpid < 0)
        {
            break;
        }
    }
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-25 21:03:06
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int ret = 0;
    //创建socket
    int lfd = soctet(AF_INET, SOCK_STREAM, 0);

    //设置端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, sizeof(int));

    struct sockaddr_in serv;
    bzero(&serv, sizeof(serv));
    serv.sin_famaily = AF_INET;
    serv.sin_port = htons(8888);
    serv.sin_addr.s_addr = htonl(INADDR_ANY);

    ret = bind(lfd, (struct sockaddr *)&serv, sizeof(serv));
    if (ret < 0)
        perror("bind");


    ret = listen(lfd, 128);
    if (ret < 0)
        perror("listen");

    //阻塞SIGCHLD信号
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);
    sigprocmask()

    ret = accept(lfd, NULL, NULL);
    if (ret < 0)
        perror("accept");


    return 0;
}

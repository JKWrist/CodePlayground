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
#include <ctype.h> //toupper

#include <sys/socket.h> //setsockopt  accept
#include <sys/wait.h>
#include <arpa/inet.h> //htons inet_ntop inet_pton
#include <netinet/in.h>

// const char *
// inet_ntop(int af, const void *restrict src, char *restrict dst,
//           socklen_t size);

// int inet_pton(int af, const char *restrict src, void *restrict dst);

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
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    //设置端口复用
    int opt = 1;
    setsockopt(lfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(int));

    struct sockaddr_in serv;
    bzero(&serv, sizeof(serv));
    serv.sin_family = AF_INET;
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
    sigprocmask(SIG_BLOCK, &mask, NULL);

    int cfd;
    char sIP[16];
    pid_t pid;
    socklen_t len;
    struct sockaddr_in client;

    while (1)
    {
        memset(sIP, 0, sizeof(sIP));
        len = sizeof(client);
        bzero(&client, sizeof(client));
        cfd = accept(lfd, (struct sockaddr *)&client, &len);
        if (cfd < 0)
            perror("accept");

        printf("client [%s] [%d]\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, sIP, sizeof(sIP)) \
                                        , ntohs(client.sin_port));

        //创建子进程
        pid = fork();
        if(pid < 0)
        {
            perror("fork error");
            close(lfd);
            return -1;
        }
        else if(0 == pid)
        {
            //子进程
            close(lfd);
            int i = 0;
            int n;
            char buf[1024];
            while (1)
            {
                memset(buf, 0, sizeof(buf));
                
                n = read(cfd, buf, sizeof(buf));
                if (n  < 0)
                {
                    perror("read");
                }
                printf("read %d buf %s\n", cfd, buf);

                for(int j = 0; j < n; j++)
                {
                    buf[j] = toupper(buf[j]);
                }
                
                printf("buf %s\n", buf);
                write(cfd, buf, n);
            }
            
        }
        else if(pid > 0)
        {
            //父进程
            close(cfd);
        }
    }

    close(lfd);
    
    return 0;
}

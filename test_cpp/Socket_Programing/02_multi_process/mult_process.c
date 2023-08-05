#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <arpa/inet.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-19 21:05:44
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    struct sockaddr_in serv_addr;
    int lfd = socket(AF_INET, SOCK_STREAM, 0);
    printf("socket lfd %d\n", lfd);

    bzero(&serv_addr, sizeof(serv_addr));
    // if (IP == NULL)
    // {
        //如果这样使用 0.0.0.0,任意ip将可以连接
        serv_addr.sin_addr.s_addr = INADDR_ANY;
    // }
    // else
    // {
    //     if (inet_pton(AF_INET, IP, &serv_addr.sin_addr.s_addr) <= 0)
    //     {
    //         perror(IP); //转换失败
    //         exit(1);
    //     }
    // }
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8888);
    int ret = bind(lfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if(ret != 0)
    {
        printf("bind error\n");
    }
    
    listen(lfd, 256);

    pid_t pid;
    int cfd;
    char sIP[16];

    socklen_t len;
    struct sockaddr_in client;

    while (1)
    {
        //接受新的连接
        len = sizeof(client);
        memset(sIP, 0x00, sizeof(sIP));
        cfd = accept(lfd, (struct sockaddr *)&client, &len);
        printf("accept  %d\n", cfd);

        printf("client:[%s] [%d]\n", inet_ntop(AF_INET, &client.sin_addr.s_addr, sIP, sizeof(sIP)),\
               ntohs(client.sin_port));

        //接受一个新的连接，创建一个子进程，让子进程完成数据的收发操作
        pid = fork();
        if(pid < 0)
        {
            perror("fork error");
            exit(-1);
        }
        else if(pid == 0)
        {
            //子进程，关闭监听文件描述符
            close(lfd);

            int i = 0;
            int n;
            char buf[1024] = {0};
            while (1)
            {
                memset(buf, 0, sizeof(buf));

                //读数据
                n = read(cfd, buf, sizeof(buf));
                if (n <= 0)
                {
                    printf("read error or client closed, n = [%d]\n", n);
                    break;
                }
                printf("pid[%d] port:[%d], readn:[%d], buf:[%s]\n", getpid(), ntohs(client.sin_port), n, buf);

                //将小写转换为大写
                for (int i = 0; i < n; i++)
                {
                    buf[i] = toupper(buf[i]);
                }

                //发送数据
                write(cfd, buf, n);
            }
            
            //关闭cfd
            close(cfd);
            exit(0);
        }
        else if(pid > 0)
        {
            close(cfd);
        }
        
    }

    close(lfd);
    return 0;
}

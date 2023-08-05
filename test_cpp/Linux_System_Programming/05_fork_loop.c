#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-21 14:20:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int i = 0;
    for(; i < 3; i++)
    {
        pid_t pid = fork();
        if(pid < 0)
        {
            perror("fork error");
        }
        else if(pid > 0)
        {
            printf("[%d] fater [%d] [%d]\n", i, getpid(), getppid());
            usleep(1000 * 1000);
        }
        else if(pid == 0)
        {
            break;
            printf("[%d]------child [%d] [%d]\n", i, getpid(), getppid());
            usleep(1000 * 500);
        }
    }

    if( i == 0)
    {
        //第一个子进程
        printf("pid:[%d] ppid:[%d]\n", getpid(), getppid());
    }
    else if( i == 1)
    {
        //第二个子进程
        printf("pid:[%d] ppid:[%d]\n", getpid(), getppid());
    }
    else if( i == 2)
    {
        //第三个子进程
        printf("pid:[%d] ppid:[%d]\n", getpid(), getppid());
    }    
    else if( i == 3)
    {
        //父进程
        printf("pid:[%d] ppid:[%d]\n", getpid(), getppid());
    }

    sleep(10);

    return 0;
}

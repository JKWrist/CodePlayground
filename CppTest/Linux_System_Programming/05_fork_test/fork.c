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
 *  创建日期：2021-10-21 15:42:11
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    printf("father pid:[%d] ppid:[%d]\n", getpid(), getppid());
    int i = 0;
    for (; i < 4; i++)
    {
        pid_t pid = fork();
        if(pid < 0)
        {
            perror("fork error");
        }
        else if( pid > 0)
        {
            //printf("father\n");
        }
        else if( pid == 0)
        {
            break;
            printf("child\n");
        }
    }

    if(0 == i)
    {
        printf("child pid:[%d] ppid:[%d]\n", getpid(), getppid());
        execlp("gcc", "gcc", "-o", "printf_argv.out", "printf_argv.c", NULL);
    }
    else if(1 == i)
    {
        printf("child pid:[%d] ppid:[%d]\n", getpid(), getppid());
         execlp("gcc", "gcc", "-o", "segment_fault.out", "segment_fault.c", NULL);
    }
    else if(2 == i)
    {
        printf("child pid:[%d] ppid:[%d]\n", getpid(), getppid());
        execl("./printf_argv.out", "printf_argv.out", "1", "2", "3", NULL);
    }
    else if(3 == i)
    {
        printf("child pid:[%d] ppid:[%d]\n", getpid(), getppid());
        execl("./segment_fault.out", "segment_fault.out", "1", "2", "3", NULL);
    }
    else
    {
        sleep(6);
    }

    return 0;
}

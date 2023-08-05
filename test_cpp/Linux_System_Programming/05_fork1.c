#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int g_var = 99;

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-21 10:48:17
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //创建子进程
    pid_t pid = fork();
    if(pid < 0)
    {
        //fork失败
        perror("fork error");
        return -1;
    }
    else if( pid > 0)
    {
        //父进程
        printf("fork return = %d\n", pid);
        printf("father pid=[%d], ppid[%d]\n", getpid(), getppid());
        g_var++;
        printf("father g_var %d  %p\n", g_var, &g_var);
    }
    else if( pid == 0)
    {
        //子进程
        printf("child pid=[%d], ppid[%d]\n", getpid(), getppid());
        printf("child g_var %d  %p\n", g_var, &g_var);
    }
    return 0;
}

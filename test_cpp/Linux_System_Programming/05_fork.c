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
 *  创建日期：2021-10-20 20:53:50
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    printf("brefore fork pid = %d\n", getpid());

    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if(pid > 0)
    {   
        printf("父进程\n");
        printf("fork()返回值  [%d]\n", pid);
        printf("father pid==[%d], fpid==[%d]\n", getpid(), getppid());
        sleep(1);
    }
    else if(pid == 0)
    {
        printf("子进程\n");
        printf("child pid==[%d], fpid==[%d]\n", getpid(), getppid());
    }

    printf("after fork pid = %d\n", getpid());
    return 0;
}

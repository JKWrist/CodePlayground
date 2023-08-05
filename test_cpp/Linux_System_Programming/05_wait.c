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
 *  创建日期：2021-10-21 14:42:00
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
        perror("fork error");
    }
    else if(pid > 0)
    {
        printf("father pid:[%d] ppid:[%d]\n", getpid(), getppid());
        int status;
        pid_t wpid = wait(&status);
        printf("wait return %d\n", wpid);

        printf("status %d\n", status);

        if(WIFEXITED(status))
        {
            printf("child normal exit, status == %d\n", WEXITSTATUS(status));
        }
        else if(WIFSIGNALED(status))
        {
            printf("child kill by signal == %d\n", WTERMSIG(status));
        }

    }
    else if(pid == 0)
    {
        printf("child pid:[%d] ppid:[%d]\n", getpid(), getppid());
        sleep(1);
        return 2;
    }

    return 0;
}

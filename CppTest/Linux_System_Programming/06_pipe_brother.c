#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-26 20:53:50
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //创建管道
    // int
    // pipe(int fildes[2]);

    int fd[2];
    int ret = pipe(fd);
    if (ret < 0)
    {
        perror("pipe error");
        return -1;
    }
    int i;
    //创建子进程
    for (i = 0; i < 2; i++)
    {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork error");
        }
        else if (pid == 0)
        {
            printf("child %d\n", i);
        }
        else if (pid > 0)
        {
            break;
            printf("father %d\n", i);
        }
    }

    if (i == 0)
    {
        // close(fd[0]);

        // //将标准输出重定向到管道的写端
        // dup2(fd[1], STDOUT_FILENO);

        // execlp("ps", "ps", "aux", NULL);
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);

        perror("execlp error");
    }
    else if (i == 1)
    {
        //sleep(1);

        // close(fd[1]);

        // dup2(fd[0], STDIN_FILENO);

        // execlp("grep", "grep", "bash", NULL);
        printf("child \n");
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("grep", "grep", "--color=auto", "bash", NULL);
        
        perror("execlp error");
    }
    else
    {
        wait(NULL);
    }
    return 0;
}

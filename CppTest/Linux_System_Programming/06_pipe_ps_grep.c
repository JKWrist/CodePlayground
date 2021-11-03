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
 *  创建日期：2021-10-22 18:03:21
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //创建管道
    
    int fd[2];
    int ret = pipe(fd);
    if(ret < 0)
    {
        perror("pipe error");
        return -1;
    }
    
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork error");
    }
    else if(pid > 0)
    {
        printf("father \n");
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
    }
    else if(pid == 0)
    {
        printf("child \n");
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execlp("grep", "grep", "--color=auto", "bash", NULL);
    }

    return 0;
}

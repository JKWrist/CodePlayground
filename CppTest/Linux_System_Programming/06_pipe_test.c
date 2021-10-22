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
 *  创建日期：2021-10-22 16:20:45
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //int pipe(int pipefd[2]);

    //创建管道
    int fd[2] = {0};
    int ret = pipe(fd);

    if(ret < 0)
    {
        perror("pipe error");
        return -1;
    }
    printf("pipe size == [%ld]\n", fpathconf(fd[0], _PC_PIPE_BUF));
    printf("pipe size == [%ld]\n", fpathconf(fd[0], _PC_PIPE_BUF));

    
    return 0;
}

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
 *  创建日期：2021-10-22 11:18:00
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

    //创建子进程
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork error");
        return -1;
    }
    else if (pid > 0)
    {
        printf("father\n");
        //关闭读端
        close(fd[0]);
        usleep(1000 * 500);
        write(fd[1], "hello world", strlen("hello world"));
        wait(NULL);
    }
    else if (pid == 0)
    {
        printf("child\n");
        //关闭写端
        close(fd[1]);
        char buf[64] = {0};
        read(fd[0], buf, sizeof(buf));
        perror("asdasd");
        printf("child read over : %s\n", buf);
    }

    return 0;
}

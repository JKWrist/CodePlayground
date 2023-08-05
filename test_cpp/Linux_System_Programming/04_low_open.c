#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-13 21:01:03
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void error_handling(char *message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-13 21:01:03
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{

    char buf[] = "Let's go!";
    int fd = open("data.txt", O_CREAT | O_WRONLY | O_TRUNC);
    if (-1 == fd)
    {
        error_handling("open() error");
    }
    printf("file descriptor %d\n", fd);

    if (-1 == write(fd, buf, sizeof(buf)))
    {
        error_handling("write() error");
    }
    close(fd);
    return 0;
}

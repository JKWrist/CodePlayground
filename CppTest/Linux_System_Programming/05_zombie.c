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
 *  创建日期：2021-10-21 11:09:33
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork error");
    }
    else if (pid > 0)
    {
        printf("father\n");
        sleep(15);
    }
    else
    {
        printf("child\n");
    }
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

void myfunc(int signo)
{
    int fd = open("mydemon.txt", O_RDWR | O_CREAT | O_APPEND, 0755);
    if(fd < 0)
    {
        perror("open error");
        return;
    }

    //获取当前系统时间
    time_t t;
    
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-03 21:24:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    
    return 0;
}

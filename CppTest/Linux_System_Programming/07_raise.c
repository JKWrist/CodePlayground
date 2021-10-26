#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

void sigHandler(int signo)
{
    printf("%d\n", signo);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-26 21:55:09
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    signal(SIGINT, sigHandler); 
    raise(SIGINT);

    abort();

    while (1)
    {
        sleep(10);
    }
    
    return 0;
}

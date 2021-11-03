#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

void sigHandler(int signo)
{
    printf("%d\n", signo);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-26 21:43:27
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //注册信号处理函数
    signal(SIGINT, sigHandler);
    signal(SIGALRM, sigHandler);

    int n = alarm(5);
    printf("first : n = [%d]\n", n);
    while (1)
    {
        sleep(10);
    }
    return 0;
}

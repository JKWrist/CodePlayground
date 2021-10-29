#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

//信号处理函数
void sighandler(int signo)
{
    printf("signo = [%d]\n", signo);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-28 20:28:39
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //注册信号函数
    struct sigaction act;
    act.sa_handler = sighandler;

    //在信号处理函数执行期间， 不阻塞任何信号
    sigemptyset(&act.sa_mask);

    //阻塞SIGQUIT信号
    sigaddset(&act.sa_mask, SIGQUIT);

    //sa_flags 可以指定信号的行为
    act.sa_flags = 0;

    sigaction(SIGINT, &act, NULL);

    signal(SIGQUIT, sighandler);

    while (1)
    {
        sleep(10);
    }
    
    return 0;
}

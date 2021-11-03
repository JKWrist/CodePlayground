#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/time.h>
#include <signal.h>

void sighandler(int signo)
{
    printf("signo [%d]\n", signo);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-28 21:07:12
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    struct sigaction st;
    st.sa_handler = sighandler;
    sigemptyset(&st.sa_mask);
    st.sa_flags = 0;

    sigaction(SIGALRM, &st, NULL);

    struct itimerval stime;
    stime.it_value.tv_sec = 1;
    stime.it_value.tv_usec = 0;

    stime.it_interval.tv_sec = 2;
    stime.it_interval.tv_usec = 50000;

    setitimer(ITIMER_REAL, &stime, NULL);

    while (1)
    {
        sleep(10);
    }

    return 0;
}

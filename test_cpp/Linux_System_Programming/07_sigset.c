#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

void sighandler(int signo)
{
    printf("[%d]\n", signo);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-28 19:52:01
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //注册SIGINT和SIGQUIT信号处理函数
    signal(SIGINT, sighandler);
    signal(SIGQUIT, sighandler);

    //定义sigset_t类型变量
    sigset_t pending, mask, oldmask;

    //sigset_t 变量初始化
    sigemptyset(&pending);
    sigemptyset(&mask);
    sigemptyset(&oldmask);

    //将SIGINT和SIGQUIT加入到阻塞信号集中
    sigaddset(&mask, SIGINT);
    sigaddset(&mask, SIGQUIT);

    //将mask中的SIGINT和SIGQUIT信号加入到阻塞信号集中
    //sigprocmask(SIG_BLOCK, &mask, NULL);
    sigprocmask(SIG_BLOCK, &mask, &oldmask);

    int i = 1;
    int k = 1;

    while (1)
    {
        //获取未决信号集
        sigpending(&pending);

        for(i = 1; i < 32; i++)
        {
            //判断某个信号是否在集合中
            if(sigismember(&pending, i) == 1)
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
            
        }
        printf("\n");

        if(k++ % 10 == 0)
        {
            //阻塞信号集中解除对SIGINT和SIGQUIT的阻塞
            //sigprocmask(SIG_SETMASK, &oldmask, NULL);
            sigprocmask(SIG_SETMASK, &oldmask, NULL);
        }
        else
        {
            sigprocmask(SIG_BLOCK, &mask, NULL);
        }

        sleep(1);
    }
    
    return 0;
}

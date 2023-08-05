#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

/*
sigprocmask
功能描述：设定对信号屏蔽集内的信号的处理方式(阻塞或不阻塞)。
用法：
#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
参数：
how：用于指定信号修改的方式，可能选择有三种

SIG_BLOCK //加入信号到进程屏蔽。
SIG_UNBLOCK //从进程屏蔽里将信号删除。
SIG_SETMASK //将set的值设定为新的进程屏蔽。

set：为指向信号集的指针，在此专指新设的信号集，如果仅想读取现在的屏蔽值，可将其置为NULL。
oldset：也是指向信号集的指针，在此存放原来的信号集。
返回说明：
成功执行时，返回0。失败返回-1，errno被设为EINVAL。
*/
static void sig_quit(int signo)
{
    printf("caught SIGQUIT\n");
    signal(SIGQUIT, sig_quit); //将SIGQUIT的动作设为缺省值
}

int main()
{
    sigset_t newmask;
    sigset_t oldmask;
    sigset_t pendmask;

    signal(SIGQUIT, sig_quit); //信号量捕捉函数，捕捉到SIGQUIT，跳转到函数指针sig_quit处执行

    while(1)
    {
        printf("SIGQUIT blocked\n");
        sigemptyset(&newmask);        //初始化信号量集
        sigaddset(&newmask, SIGQUIT); //将SIGQUIT添加到信号量集中
        sigprocmask(SIG_BLOCK, &newmask, &oldmask); //将newmask中的SIGQUIT阻塞掉，并保存当前信号屏蔽字到Oldmask
        sleep(5);              //休眠5秒钟，这里做说明:在5s休眠期间，任何SIGQUIT信号都会被阻塞，如果在5s内收到任何键盘的quit信号，则此时会把这些信息存在内核的队列中，等待5s结束后，可能要处理此信号。
        
        sigpending(&pendmask); //检查信号是悬而未决的,if (sigismember(&pendmask, SIGQUIT))//SIGQUIT是悬而未决的。所谓悬而未决，是指SIGQUIT被阻塞还没有被处理
        {
            if (sigismember(&pendmask, SIGQUIT))
                printf("sigprocmask SIGQUIT pending\n");
        }
       
    
        /**开始处理信号，调用信号处理函数*/
        printf("SIGQUIT unblocked\n");
        sigprocmask(SIG_SETMASK, &oldmask, NULL); //恢复被屏蔽的信号SIGQUIT
        signal(SIGQUIT, sig_quit);
        sleep(5); //再次休眠5秒钟
    }

    return (0);
}
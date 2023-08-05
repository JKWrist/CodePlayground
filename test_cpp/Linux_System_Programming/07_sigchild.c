#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>

void waitchild(int signo)
{
    printf("waitchild\n");
    pid_t wpid;

    while(1)
    {
        wpid = waitpid(-1, NULL, WNOHANG);

        if(wpid > 0)
        {
            printf("child is quit, wpid = [%d]\n", wpid);
        }
        else if(wpid == 0)
        {
            printf("child is living, wpid = [%d]\n", wpid);
            break;
        }
        else
        {
            printf("no child is living, wpid = [%d]\n", wpid);
            break;
        }
    }
}

void test_signal()
{
    int i = 0;
    int n = 3;

    for (i = 0; i < n; i++)
    {
        //fork子进程
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            return;
        }
        else if (pid > 0)
        {
            printf("father pid = %d, ppid = %d\n", getpid(), getppid());
        }
        else if (pid == 0)
        {
            printf("child pid = %d, ppid = %d\n", getpid(), getppid());
            break;
        }
    }

    if (3 == i)
    {
        printf("father = [%d], i = [%d]\n", getpid(), i);
        signal(SIGCHLD, waitchild);

        while (1)
        {
            sleep(2);
        }
    }

    if (0 == i)
    {
        printf("child = [%d], i = [%d]\n", getpid(), i);
    }
    else if (1 == i)
    {
        printf("child = [%d], i = [%d]\n", getpid(), i);
    }
    else if (2 == i)
    {
        printf("child = [%d], i = [%d]\n", getpid(), i);
    }
}

void test_sigaction()
{
    int i = 0;
    int n = 3;

    //将SIGCHLD信号阻塞
    sigset_t mask;
    sigemptyset(&mask);
    sigaddset(&mask, SIGCHLD);
    sigprocmask(SIG_BLOCK, &mask, NULL);

    for (i = 0; i < n; i++)
    {
        //fork子进程
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("fork error");
            return;
        }
        else if (pid > 0)
        {
            printf("father pid = %d, ppid = %d\n", getpid(), getppid());
        }
        else if (pid == 0)
        {
            printf("child pid = %d, ppid = %d\n", getpid(), getppid());
            break;
        }
    }

    if (3 == i)
    {
        printf("father = [%d], i = [%d]\n", getpid(), i);
        //注册信号处理函数
        struct sigaction act;
        act.sa_handler = waitchild;
        act.sa_flags = 0;
        sigemptyset(&act.sa_mask);
        //sleep(2);
        sigaction(SIGCHLD, &act, NULL);

        //解除对信号SIGCHLD的阻塞
        sigprocmask(SIG_UNBLOCK, &mask, NULL);

        while (1)
        {
            sleep(1);
        }
    }

    if (0 == i)
    {
        printf("child = [%d], i = [%d]\n", getpid(), i);
        sleep(1);
    }
    else if (1 == i)
    {
        printf("child = [%d], i = [%d]\n", getpid(), i);
        sleep(2);
    }
    else if (2 == i)
    {
        printf("child = [%d], i = [%d]\n", getpid(), i);
        sleep(3);
    }
}

//父进程使用SIGCHLD信号完成对子进程的回收
/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-28 21:40:26
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //test_signal();

    test_sigaction();

    return 0;
}

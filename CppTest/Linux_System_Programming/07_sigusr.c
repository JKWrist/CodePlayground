#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

int num = 0;
int flag;

void func1(int signo)
{
    printf("F:[%d]\n", num);
    num += 2;
    flag = 0;
    sleep(1);
}

void func2(int signo)
{
    printf("C:[%d]\n", num);
    num += 2;
    flag = 0;
    sleep(1);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-31 21:40:49
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int ret;
    pid_t pid;

    pid = fork();
    if (pid < 0)
    {
        perror("fork error");
    }
    else if (pid > 0)
    {
        printf("F:[%d] C:[%d]\n", getpid(), pid);

        num = 0;
        flag = 1;
        signal(SIGUSR1, func1);
        while (1)
        {
            if (flag == 0)
            {
                kill(pid, SIGUSR2);
                flag = 1;
            }
            sleep(1);
        }
    }
    else if (pid == 0)
    {
        printf("C:[%d]\n", getpid());

        num = 1;
        flag = 0;   //先让子进程给父进程发信号
        signal(SIGUSR2, func2);
        while (1)
        {
            if (flag == 0)   
            {
                kill(getppid(), SIGUSR1);
                flag = 1;
            }
            sleep(1);
        }
    }

    return 0;
}

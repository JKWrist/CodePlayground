#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

int num;
int flag;

void child(int signo)
{
    printf("c: num %d\n", num);
    num += 2;
    flag = 1;
}

void father(int signo)
{
    printf("f: num %d\n", num);
    num += 2;
    flag = 1;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-03 20:40:20
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("fork error");
    }
    else if (pid == 0)
    {
        //child
        num = 1;
        flag = 1;
        signal(SIGUSR1, child);
        while (1)
        {
            //printf("11111\n");
            if (1 == flag)
            {
                //kill(SIGUSR2, getppid());
                flag = 0;
                kill(getppid(), SIGUSR2);
            }
            sleep(1);
        }
    }
    else if (pid > 0)
    {
        //father
        num = 0;
        flag = 0;
        signal(SIGUSR2, father);
        while (1)
        {
            //printf("2222\n");
            if (1 == flag)
            {
                flag = 0;
                kill(pid, SIGUSR1);
            }
            sleep(1);
        }
    }

    return 0;
}

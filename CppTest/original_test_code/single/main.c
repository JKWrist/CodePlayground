#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("pid = %d\n", getpid());
    pid_t pid = fork();
    if (pid < 0)
    {
        printf("fork error\n");
        return -1;
    }
    else if (pid == 0)
    {
        //这段代码只有子进程能够运行到，因为在子进程中fork的返回值为0
        printf("This is the child!pid = %d\n", getpid());
        sleep(5);
        exit(0); //退出进程
    }
    else if (pid > 0)
    {
        //这段代码只有父进程能运行到
        printf("This is the parent!pid = %d\n", getpid());
    }
    //当fork成功时下面的代码父子进程都会运行到
    while (1)
    {
        printf("-------------pid = %d\n", getpid());
        sleep(1);
    }
    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <sys/time.h>

void myfunc(int signo)
{
    int fd = open("mydemon.txt", O_RDWR | O_CREAT | O_APPEND, 0755);
    if (fd < 0)
    {
        perror("open error");
        return;
    }

    //获取当前系统时间
    time_t t;
    time(&t);
    char *p = ctime(&t);

    //将时间写入文件
    write(fd, p, strlen(p));
    close(fd);

    return;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-03 21:24:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    pid_t pid = fork();
    if (pid < 0 || pid > 0)
    {
        exit(1);
    }

    //子进程调用setsid函数创建会话
    setsid();

    //改变当前目录
    chdir("deamon_data.txt");

    //改变文件掩码
    umask(0000);

    //关闭标准输入，输出和输出文件描述符
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    //核心操作
    //注册信号处理函数
    struct sigaction act;
    act.sa_handler = myfunc;
    act.sa_flags = 0;
    sigemptyset(&act.sa_mask);
    sigaction(SIGALRM, &act, NULL);

    //设置闹钟
    struct itimerval tm;
    tm.it_interval.tv_sec = 2;
    tm.it_interval.tv_usec = 0;

    tm.it_value.tv_sec = 2;
    tm.it_value.tv_usec = 0;

    setitimer(ITIMER_REAL, &tm, NULL);

    while (1)
    {
        sleep(1);
    }

    return 0;
}

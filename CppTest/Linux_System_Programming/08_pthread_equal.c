#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

//线程执行函数
void * mythread(void * arg)
{
    printf("chlid thread, pid = [%d], thread id = [%d]\n", getpid(), pthread_self());
    sleep(5);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-05 21:40:46
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread, NULL);
    if(ret != 0)
    {
        printf("%s\n", strerror(ret));
    }

    if(pthread_equal(pthread_self(), pthread_self()))
    {
        printf("equal\n");
    }

    sleep(5);

    return 0;
}

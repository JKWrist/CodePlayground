#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

void * mythread(void * arg)
{
    printf("child thread, pid == [%d], id == [%d]\n", getpid(), thread_self());
    sleep(3);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-08 22:07:32
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread, BULL);
    return 0;
}

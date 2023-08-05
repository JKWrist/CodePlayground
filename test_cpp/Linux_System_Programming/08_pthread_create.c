//gcc 08_pthread_create.c -lpthread

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>


/****************************************************************
 *  函数名称：
 *  创建日期：2021-11-05 20:40:41
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void * mythread(void * arg)
{
    printf("main thread, pid == [%d], id == [%ld]\n", getpid(), pthread_self());
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-05 20:19:04
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    // int
    // pthread_create(pthread_t * thread, const pthread_attr_t *attr,
    //                void *(*start_routine)(void *), void *arg);
    // 创建子线程
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread, NULL);

    if(ret != 0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
        return -1;
    }

    printf("main thread, pid == [%d], id == [%ld]\n", getpid(), pthread_self());

    sleep(1);

    return 0;
}

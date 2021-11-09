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
    sleep(3);
    printf("child thread, pid = [%d], id = [%ld]\n", getpid(), pthread_self());
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
    int ret = pthread_create(&thread, NULL, mythread, NULL);
    if(ret != 0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
    }
    printf("main thread, pid = [%d], id = [%ld]\n", getpid(), pthread_self());

    //设置子线程为分离属性
    ret = pthread_detach(thread);
    if(ret != 0)
    {
        printf("pthread_detach error [%s]\n", strerror(ret));
    }

    //子线程设置分离属性，则pthread_join不再阻塞，立刻返回
    ret = pthread_join(thread, NULL);

    if(ret != 0)
    {
        printf("pthread_join error [%s]\n", strerror(ret));
    }

    //目的是为了让子线程能够执行起来
    sleep(1);
    
    //主线程退出，不影响到子线程
    pthread_exit(NULL);
    return 0;
}

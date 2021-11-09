#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

//创建线程的时候设置分离属性
void * mythread(void *arg)
{
    printf("chlid thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());
    sleep(2);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-08 20:02:57
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //定义pthread_attr_t 类型的变量
    pthread_attr_t attr;

    //初始化attr变量
    pthread_attr_init(&attr);

    //设置atte为分离属性
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_t thread;

    int ret = pthread_create(&thread, &attr, mythread, NULL);
    if(ret != 0)
    {
        printf("pthread_create error, [%s\n]", strerror(ret));
        return -1;
    }

    printf("main thread, pid == [%d], id ==[%ld]\n", getpid(), pthread_self());

    //释放线程属性
    pthread_attr_destroy(&attr);

    //验证子线程是否为分离属性
    ret = pthread_join(thread, NULL);
    if(ret != 0)
    {
        printf("pthread_create error, [%s\n]", strerror(ret));
        return -1;
    }
    
    //sleep(3)

    return 0;
}

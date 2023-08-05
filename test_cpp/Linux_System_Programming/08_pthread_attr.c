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
void * mythread1(void *arg)
{
    while (1)
    {
        printf("chlid thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());
        sleep(2);
    }
}

void *mythread2(void *arg)
{
    while (1)
    {
        usleep(1 * 1000 * 1000);
        printf("thread1 running...!\n");
    }
    printf("Leave thread1!\n");

    return NULL;
}

void test01()
{
    //定义pthread_attr_t 类型的变量
    pthread_attr_t attr;

    //初始化attr变量
    pthread_attr_init(&attr);

    //设置atte为分离属性
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

    pthread_t thread;
    int ret = pthread_create(&thread, &attr, (void *)mythread1, NULL);

    if (ret != 0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
        return;
    }

    printf("main thread, pid == [%d], id ==[%ld]\n", getpid(), pthread_self());

    //释放线程属性
    pthread_attr_destroy(&attr);

    //验证子线程是否为分离属性
    // ret = pthread_join(thread, NULL);
    // if (ret != 0)
    // {
    //     //将出错的日志写清楚， 以防找不到出错点
    //     printf("pthread_join error, [%s]\n", strerror(ret));
    //     return;
    // }
    
}

void test02()
{
    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // 设置分离属性

    pthread_t tid;
    int ret = pthread_create(&tid, &attr, mythread2, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
        return;
    }
    pthread_attr_destroy(&attr);
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
    test01();
    
    //test02();

    sleep(10);

    printf("Leave main thread!\n");

    //“分离线程”运行结束还是一样退出。只是“分离线程”的资源是有系统回收的。
    pthread_exit(NULL);

    //在进程主函数（main()）中调用pthread_exit()，只会使主函数
    //所在的线程（可以说是进程的主线程）退出；如果是return，
    //编译器将使其调用进程退出的代码（如_exit()），从而导致进程
    //及其所有线程（包括分离线程）结束运行。
    return 0;
}

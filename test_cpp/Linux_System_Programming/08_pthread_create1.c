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


struct  Test
{
    int data;
    char name[64];
};

//线程执行函数
void * mythread1(void * arg)
{
    int num = *(int *)arg;
    printf("[%d]\n", num);
    printf("%d, %ld\n", getpid(), pthread_self());
}

//线程执行函数
void *mythread2(void *arg)
{
    struct Test tmp = *(struct Test *)arg;
    printf("%d %s\n", tmp.data, tmp.name);
    printf("%d, %ld\n", getpid(), pthread_self());
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-05 20:39:47
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    //int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
    //                      void *(*start_routine) (void *), void *arg);

    int n = 10;
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread1, &n);
    if (ret != 0)
    {
        printf("%s\n", strerror(ret));
    }
    

    struct Test t;
    memset(&t, 0x00, sizeof(struct Test));
    t.data = 98;
    strcpy(t.name, "feifei");
    ret = pthread_create(&thread, NULL, mythread2, &t);
    if (ret != 0)
    {
        printf("%s\n", strerror(ret));
    }

    sleep(1);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>

pthread_mutex_t mutex;

void *mythread1(void *arg)
{
    while (1)
    {
        //加锁
        //pthread_mutex_lock(&mutex);
        printf("hello");
        sleep(rand() % 3);
        printf("world\n");
        //解锁
        //pthread_mutex_unlock(&mutex);

        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

void *mythread2(void *args)
{
    while (1)
    {
        //pthread_mutex_lock(&mutex);
        printf("HELLO");
        sleep(rand() % 3);
        printf("WORLD\n");
        //pthread_mutex_unlock(&mutex);

        sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

void test01()
{
    int ret;
    pthread_t thread1;
    pthread_t thread2;

    //随机数种子
    srand(time(NULL));

    //互斥锁初始化
    pthread_mutex_init(&mutex, NULL);

    ret = pthread_create(&thread1, NULL, mythread1, NULL);
    if (ret != 0)
    {
        printf("pthread_create error\n");
    }

    ret = pthread_create(&thread2, NULL, mythread2, NULL);
    if (ret != 0)
    {
        printf("pthread_create error\n");
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    pthread_mutex_destroy(&mutex);
}


/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-09 21:10:06
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    test01();

    return 0;
}

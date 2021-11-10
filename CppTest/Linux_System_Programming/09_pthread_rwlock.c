#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>

int number = 0;

//定义一把读写锁
pthread_rwlock_t rwlock;

void *thread_write(void * arg)
{
    int i = *(int *)arg;
    int cur;
    while (1)
    {
        //加写锁
        pthread_rwlock_wrlock(&rwlock);

        cur = number;
        cur++;
        number = cur;
        printf("[%d]-W:[%d]\n", i, cur);

        //解锁
        pthread_rwlock_unlock(&rwlock);
        sleep(rand()%3);
    }
}

//读线程回调函数
void *thread_read(void * arg)
{
    int i = *(int *)arg;
    int cur;
    while (1)
    {
        //加读锁
        pthread_rwlock_rdlock(&rwlock);

        cur = number;
        printf("[%d]-R:[%d]\n", i, cur);

        //解锁
        pthread_rwlock_unlock(&rwlock);
        sleep(rand()%3);
    }
    
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-10 20:25:37
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int n = 8;
    int i = 0;
    int arr[8];
    pthread_t thread[8];

    pthread_rwlock_init(&rwlock, NULL);
    
    //创建3个写线程
    for (int i = 0; i < 3; i++)
    {
        arr[i] = i;
        pthread_create(&thread[i], NULL, thread_write, &arr[i]);
    }
    
    //创建5个读进程
    for (int i = 3; i < 8; i++)
    {
        arr[i] = i;
        pthread_create(&thread[i], NULL, thread_read, &arr[i]);
    }

    //回收子线程
    for (int i = 0; i < 8; i++)
    {
        pthread_join(thread[i], NULL);
    }
    
    pthread_rwlock_destroy(&rwlock);

    return 0;
}

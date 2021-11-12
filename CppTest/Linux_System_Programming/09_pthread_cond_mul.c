#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>


typedef struct NODE
{
    int data;
    struct NODE *next;
} NODE;

NODE *head = NULL;

pthread_mutex_t mutex;

pthread_cond_t cond;

void *producer(void *arg)
{
    printf("producer\n");
    NODE *pNode;
    int n = *(int *)arg;
    while (1)
    {
        pNode->data = rand() % 1000;
        pthread_mutex_lock(&mutex);

        head->next = pNode;
        head = pNode;
        printf("P [%d]:[%d]\n", n, pNode->data);

        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&cond);

        usleep(rand() % 500000);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    printf("consumer\n");
    NODE *pNode;
    int n = *(int *)arg;
    while (1)
    {
        pthread_mutex_lock(&mutex);

        if (NULL == head)
        {
            pthread_cond_wait(&cond, &mutex);
        }

        pthread_mutex_lock(&mutex);

        pNode = head;
        head = pNode->next;
        printf("C [%d]:[%d]\n", n, pNode->data);
        free(pNode);

        pthread_mutex_unlock(&mutex);
        usleep(rand() % 500000);
    }
    pthread_exit(NULL);
}

/****************************************************************
 *  函数名称：多线程情况下的条件变量
 *  创建日期：2021-11-11 21:48:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int ret;
    pthread_t thread1[5];
    pthread_t thread2[5];

    //初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    //条件变量初始化
    pthread_cond_init(&cond, NULL);

    arr[5] = {0};
    //创建生产者线程
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
        ret = pthread_create(&thread1[i], NULL, producer, &arr[i]);
        ret = pthread_create(&thread2[i], NULL, consumer, &arr[i]);
    }

    //等待线程结束
    for (int i = 0; i < 5; i++)
    {
        pthread_join(thread1[i], NULL);
        pthread_join(thread2[i], NULL);
    }

    //释放互斥锁  destroy
    pthread_mutex_destroy(&mutex);

    //释放条件变量
    pthread_cond_destroy(&cond);

    return 0;
}

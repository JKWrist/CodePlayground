#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <semaphore.h>
#include <pthread.h>

typedef struct node
{
    int data;
    struct node *next;
} NODE;

NODE *head = NULL;

sem_t sem_producer;
sem_t sem_consumer;

void *producer(void *arg)
{
    NODE *pNode = NULL;
    while (1)
    {
        //生产一个节点
        pNode = (NODE *)malloc(sizeof(NODE));
        if (NULL == pNode)
        {
            printf("malloc error\n");
            exit(-1);
        }

        pNode->data = rand() % 40;
        printf("P: [%d]\n", pNode->data);

        //加锁
        sem_wait(&sem_producer);
        pNode->next = head;
        head = pNode;
        sem_post(&sem_consumer);

        usleep(rand() % 10000);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    NODE *pNode = NULL;
    while (1)
    {
        //加锁
        sem_wait(&sem_consumer);

        printf("C: [%d]\n", head->data);
        pNode = head;
        head = head->next;
        sem_post(&sem_producer);

        free(pNode);
        pNode  = NULL;

        usleep(rand() % 10000);
    }
    pthread_exit(NULL);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-13 16:28:31
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{

    //mac下会出现崩溃的问题，ubuntu下运行正常
    
    int ret;
    pthread_t thread1;
    pthread_t thread2;

    //初始化信号量
    sem_init(&sem_producer, 0, 5);
    sem_init(&sem_consumer, 0, 0);

    //创建生产者线程
    ret = pthread_create(&thread1, NULL, producer, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
    }

    //创建消费者线程
    ret = pthread_create(&thread2, NULL, consumer, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    //destroy 此单词的拼写
    sem_destroy(&sem_producer);
    sem_destroy(&sem_consumer);

    return 0;
}

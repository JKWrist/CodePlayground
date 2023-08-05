#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

typedef struct node
{
    int data;
    struct node * next;
}NODE;

NODE * head = NULL;

//定义一把锁
pthread_mutex_t mutex;

//定义条件变量
pthread_cond_t cond;

//生产者线程
void * producer(void * arg)
{
    NODE * pNode = NULL;
    while (1)
    {
        //生产一个节点
        pNode = (NODE *)malloc(sizeof(NODE));
        if(NULL == pNode)
        {
            perror("malloc error");
            exit(-1);
        }

        pNode->data = rand()%1000;
        printf("P:[%d]\n", pNode->data);

        //加锁
        pthread_mutex_lock(&mutex);

        pNode->next = head;
        head = pNode;

        //解锁
        pthread_mutex_unlock(&mutex);

        //通知消费者结束阻塞  signal
        pthread_cond_signal(&cond);

        usleep(rand() % 500000);
    }
    pthread_exit(NULL);
}

//消费者线程
void *consumer(void * arg)
{
    NODE * pNode = NULL;
    while (1)
    {
        //加锁
        pthread_mutex_lock(&mutex);

        if (NULL == head)
        {
            //若条件不满足需要阻塞等待
            //若条件不满足，则阻塞等待并解锁
            //仔细想一下，这里假设锁住，那么生产者线程就不能获得锁，发生死锁的情况
            //若条件满足(被生产者线程调用pthread_cond_signal函数通知，解除阻塞并加锁)
            pthread_cond_wait(&cond, &mutex);
        }

        printf("C:[%d]\n", head->data);
        pNode = head;
        head = head->next;

        //解锁
        pthread_mutex_unlock(&mutex);

        free(pNode);
        pNode = NULL;

        usleep(rand() % 500000);
    }
    pthread_exit(NULL);
}
/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-11 20:43:02
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int ret;
    pthread_t thread1;
    pthread_t thread2;

    //初始化互斥锁
    pthread_mutex_init(&mutex, NULL);
    
    //条件变量初始化
    pthread_cond_init(&cond, NULL);

    //创建生产者线程
    ret = pthread_create(&thread1, NULL, producer, NULL);
    if(ret != 0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
    }

    //创建消费者线程
    ret = pthread_create(&thread2, NULL, consumer, NULL);
    if (ret != 0)
    {
        printf("pthread_create error, [%s]\n", strerror(ret));
    }

    //等待线程结束
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    
    //释放互斥锁  destroy
    pthread_mutex_destroy(&mutex);

    //释放条件变量
    pthread_cond_destroy(&cond);

    return 0;
}

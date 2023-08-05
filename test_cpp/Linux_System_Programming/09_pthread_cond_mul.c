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
    NODE *pNode = NULL;
    int n = *(int *)arg;
    while (1)
    {
        pNode = (NODE *)malloc(sizeof(NODE));
        if (NULL == pNode)
        {
            perror("malloc error");
            exit(-1);
        }
        pNode->data = rand() % 1000;
        printf("P [%d]:[%d]\n", n, pNode->data);

        pthread_mutex_lock(&mutex);
        //head->next = head;  原有写法导致崩溃，因为headnext又指向自己
        //形成了一个环，下面head赋值不为空，生产者通知消费者时候，打印空指针导致崩溃
        pNode->next = head;
        head = pNode;
        pthread_mutex_unlock(&mutex);

        pthread_cond_signal(&cond);
        usleep(rand() % 500000);
        //sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

void *consumer(void *arg)
{
    printf("consumer\n");
    NODE *pNode = NULL;
    int n = *(int *)arg;
    while (1)
    {
        pthread_mutex_lock(&mutex);
        if (NULL == head)
        {
            //若条件不满足，需要阻塞等待
            //若条件满足，解除阻塞并解锁
            //若条件满足，生产者调用pthread_cond_signal函数通知，解除阻塞
            pthread_cond_wait(&cond, &mutex);
        }
        //以上代码在生产者发信号通知之后，假设至少两个线程解除阻塞
        //第一个线程加锁，解除锁，第二个线程这时获得锁
        //也并不会阻塞在pthread_cond_wait这里,这时生产队列为空
        //消费者2去访问就会发生崩溃的情况

        //以下的代码是很重要的，存在一种情况，生产者队列只剩一个元素时
        //在消费者获得锁的时候，消费完最后一个数据，生产队列为空
        //释放锁的同时
        if (NULL == head)
        {
            pthread_mutex_unlock(&mutex);
            continue;
        }

        printf("C [%d]:[%d]\n", n, head->data);
        pNode = head;
        head = head->next;
        pthread_mutex_unlock(&mutex);

        free(pNode);
        pNode = NULL;

        usleep(rand() % 500000);
        //sleep(rand() % 3);
    }
    pthread_exit(NULL);
}

//gcc 09_pthread_cond_mul.c -lpthread

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
    int arr[5] = {0};
    pthread_t thread1[5];
    pthread_t thread2[5];

    //初始化互斥锁
    pthread_mutex_init(&mutex, NULL);

    //条件变量初始化
    pthread_cond_init(&cond, NULL);

    //创建生产者线程
    for (int i = 0; i < 5; i++)
    {
        arr[i] = i;
        printf("1111 %d", arr[i]);

        ret = pthread_create(&thread1[i], NULL, producer, &arr[i]);
        if (ret != 0)
        {
            printf("pthread_create %s\n", strerror(ret));
        }

        ret = pthread_create(&thread2[i], NULL, consumer, &arr[i]);
        if (ret != 0)
        {
            printf("pthread_create %s\n", strerror(ret));
        }

        //为什么不能写在这里呢，一个循环就写完了。pthread_join是阻塞函数
        //会等上面的创建的线程运行结束
        // //等待线程结束
        // pthread_join(thread1[i], NULL);
        // pthread_join(thread2[i], NULL);
    }

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
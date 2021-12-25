#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <errno.h>
#include <assert.h>
#include <06_threadpool.h>

#define DEFAULT_TIME 10        //10s检测一次
#define MIN_WAIT_TASK_NUM 10   //如果queue_size > MIN_WAIT_TASK_NUM 添加新的线程到线程池
#define DEFAULT_THREAD_VARY 10 //每次创建和销毁的线程的个数
#define true 1
#define false 0

typedef struct
{
    void *(*function)(void *); //函数指针，回调函数
    void *arg;                 //上面函数的参数
} threadpool_task_t;           //各子线程任务结构体

//描述线程池的相关信息
struct threadpool_t
{
    pthread_mutex_t lock;//用于锁住本结构体
    pthread_mutex_t thread_counter; //记录忙碌线程个数的锁 --busy_thr_num
    pthread_cond_t queue_not_full;  //任务队列满时，添加任务的线程阻塞，等待此条件变量
    pthread_cond_t queue_not_empty; //任务队列不为空时，通知等待任务的线程
    
    pthread_t * threads; //存放线程池中每个线程的tid，数组
    pthread_t adjust_tid;
    
};

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-12-25 21:27:47
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{

    return 0;
}

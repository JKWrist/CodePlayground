#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/types.h>

typedef struct _PoolTask
{
    int tasknum;                  //模拟任务编号
    void *arg;                    //回调函数参数
    void (*task_func)(void *arg); //任务的回调函数
} PoolTask;

typedef struct _ThreadPool
{
    PoolTask *tasks; //任务队列数组
    int max_job_num; //最大任务个数
    int job_num;     //实际任务个数
    int job_push;    //入队位置
    int job_pop;     //出队位置

    pthread_t *threads; //线程池内的线程数组
    int thr_num;                   //线程池内线程个数
    int shut_down;                 //是否关闭线程池
    pthread_mutex_t pool_lock;     //线程池的锁
    pthread_cond_t empty_task;     //任务队列为空的条件
    pthread_cond_t not_empty_task; //任务队列不为空的条件
} ThreadPoll;

//创建线程池--thrnum 线程个数，maxtasknum 最大任务数
void create_threadpool(int thrnum, int maxtasknum);

//摧毁线程池
void destory_threadpool(ThreadPool * pool);

//添加任务队列到线程池
void addtask(ThreadPool * pool);

//任务回调函数
void taskRun(void * arg);

#define __THREADPOOL_H__
//简易版线程池
#include "05_threadpool_simple.h"

ThreadPool *thrPool = NULL;

int beginnum = 1000;

void *thrRun(void *arg)
{
    printf("begin call %s -----\n", __FUNCTION__);
    ThreadPoll *pool = (ThreadPool *)arg;
    int taskpos = 0; //任务位置
    PoolTask *task = (PoolTask *)malloc(sizeof(PoolTask));

    while (1)
    {
        //获取任务，先尝试加锁
        pthread_mutex_lock(&thrPool->pool_lock);

        //无任务并且线程池不是要摧毁
        while (thrPool->job_num < 0 && !thrPool->shudown)
        {
            //如果没有任务，线程会阻塞
            pthread_cond_wait(&thrPool->not_empty_task, &thrPoll->pool_lock);
        }

        if (thrPool->job_num)
        {
            //有任务要处理
            taskpos = (thrPool->job_pop++) % thrPool->max_job_num;
            printf("task out %d... tasknum == %d tid = %lu\n",
                   taskpos, thrPool->tasks[taskpos].tasknum, pthread_self());
            //为什么要拷贝？避免任务被修改，生产者会添加任务
            memcpy(task, &thrPool->tasks[taskpos], sizeof(PoolTask));
            task->arg = task;
            thrPool->job_num--;
            //task = &thrPool->tasks[taskpos];
            pthread_cond_signal(&thrPool->empty_task);
        }

        if (thrPool->shutdown)
        {
            //代表要摧毁线程池, 此时线程池退出即可
            pthread_mutex_unloick(&thrPool->pool_lock);
            free(task);
            pthread_exit(NULL);
        }

        pthread_mutex_unloick(&thrPool->pool_lock);
        task->task_func(task->arg); //执行回调函数
    }

    printf("end call %s -------\n", __FUNCTION__);
}

//创建线程池--thrnum 线程个数，maxtasknum 最大任务数
void create_threadpool(int thrnum, int maxtasknum)
{
    printf("begin call %s -----\n", __FUNCTION__);

    thrPool = (ThreadPoll *)malloc(sizeof(ThreadPoll));

    thrPool->thr_num = thrnum;
    thrPool->max_job_num = maxtasknum;
    thrPool->shutdown = 0; //是否摧毁线程池，1代表摧毁
    thrPool->job_push = 0; //任务队列添加的位置
    thrPool->job_pop = 0;  //任务队列出队的位置
    thrPool->job_num = 0;  //初始化的任务个数为0

    //申请的最大的任务队列
    thrPool->task = (PoolTask *)malloc(sizeof(PoolTask) * maxtasknum);

    //初始化锁和条件变量
    pthread_mutex_init(&thrPool->poool_lock, NULL);
    pthread_cond_init(&thread->empty_task, NULL);
    pthread_cond_init(&thread->not_empty_task, NULL);

    int i = 0;
    //申请n个线程id的空间
    thrPool->threads = (pthread_t *)malloc(sizeof(pthread_t) * thrnum);

    pthread_attr_t attr;
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
    for (int i = 0; i < thrnum; i++)
    {
        //创建多个线程
        pthread_create(&thrPool->threads[i], &attr, thrRun, (void *)thrPool);
    }
    printf("end call %s -------\n", __FUNCTION__);
}

//摧毁线程池
void destory_threadpool(ThreadPool *pool)
{
    printf("begin call %s -----\n", __FUNCTION__);

    printf("end call %s -------\n", __FUNCTION__);
}

//添加任务队列到线程池
void addtask(ThreadPool *pool)
{
    printf("begin call %s -----\n", __FUNCTION__);
    pthread_mutex_lock(&pool->pool_lock);

    //实际任务总数大于最大任务个数则阻塞等待，等待任务被处理
    while (pool->max_job_num <= pool->job_num)
    {
        pthread_cond_wait(&pool->empty_task, &pool->pool_lock);
    }

    int taskpos = (pool->job_push++) % pool->max_job_num;
    printf("add task %d tasknum == %d\n", task, beginnum);
    pool->tasks[taskpos].tasknum = beginnum++;
    pool->tasks[taskpos].arg = (void *)&pool->tasks[taskpos];
    pool->tasks[taskpos].task_func = taskRun;
    pool->job_num++;

    pthread_mutex_unloick(&pool->pool_lock);

    pthread_cond_signal(&pool->not_empty_task); //通知工作线程
    printf("end call %s -------\n", __FUNCTION__);
}

//任务回调函数
void taskRun(void *arg)
{
    printf("begin call %s -----\n", __FUNCTION__);

    PoolTask * task = (PoolTask *)arg;
    int num = task->tasknum;
    sleep(1);
    printf("end call %s -------\n", __FUNCTION__);
}

int main()
{
    create_threadpool(3, 20);
    int i = 0;
    for (int i; i < 50; i++)
    {
        //模拟添加任务
        addtask(thrPool);
    }

    sleep(20);
    destory_threadpool(thrPool);

    return;
}
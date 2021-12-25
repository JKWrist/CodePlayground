#ifndef __THREADPOOL_H__
#define __THREADPOOL_H__

typedef struct threadpool_t threadpool_t;

/****************************************************************
 *  函数名称：threadpool_create 创建一个 threadpool_t 对象
 *  创建日期：2021-12-25 21:11:18
 *  作者：xujunze
 *  输入参数：   min_thr_num 最小进程数
 *              max_thr_num 最大进程数
 *              queue_max_size 队列中数量
 * 
 *  输出参数：thread pool 或者为空
 *  返回值：无
******************************************************************/
threadpool_t *threadpool_create(int min_thr_num, int max_thr_num, int queue_max_size);

/****************************************************************
 *  函数名称：在任务队列中增加一个任务
 *  创建日期：2021-12-25 21:14:58
 *  作者：xujunze 
 *  输入参数：   pool 增加任务的那个线程池
 *              function 任务的回调函数
 *              arg 任务回调函数的参数
 *  输出参数：无
 *  返回值：成功返回0，失败返回-1
******************************************************************/
int threadpool_add(threadpool_t *pool, void *(*function)(void *arg), void *arg);

/****************************************************************
 *  函数名称：摧毁线程池
 *  创建日期：2021-12-25 21:16:04
 *  作者：xujunze
 *  输入参数：pool 需要摧毁的线程池
 *  输出参数：无
 *  返回值：成功返回0，失败返回-1
******************************************************************/
int threadpool_destory(threadpool_t *pool);

/****************************************************************
 *  函数名称：threadpool_busy_threadnum
 *  创建日期：2021-12-25 21:23:54
 *  作者：xujunze
 *  输入参数：pool 访问的线程池
 *  输出参数：无
 *  返回值：获取忙碌线程的个数
******************************************************************/
int threadpool_busy_threadnum(threadpool_t *pool);

#endif //__THREADPOOL_H__

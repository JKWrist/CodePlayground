#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

//int pthread_create(pthread_t *thread, const pthread_attr_t *attr,
//             void *(*start_routine)(void *), void *arg)

pthread_t arr_thread[5] = {0};
int arr[5] = {0};
void *mythread(void *arg)
{
    int n = *(int *)arg;
    printf("child thread:[%d], pid = [%d], id = [%ld]\n", n, getpid(), pthread_self());
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-05 21:09:03
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    int ret = 0;

    for(int i = 0; i < 10; i++)
    {

        //这里就存在一个线程传递i不同的情况，因为创建当前进程不能马上分配到
        //CPU的时间片
        //ret = pthread_create(&arr_thread[i], NULL, mythread, &i);

        arr[i] = i;
        pthread_create(&arr_thread[i], NULL, mythread, &arr[i]);
        if (ret != 0)
        {
            printf("%s\n", strerror(ret));
        }
    }
    printf("main thread, pid==[%d], id==[%ld]\n", getpid(), pthread_self());

    sleep(100);

    return 0;
}

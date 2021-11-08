#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

struct Test
{
    int data;
    char name[64];
};

int g_var = 99;

struct Test t;

void *mythread1(void *arg)
{
    printf("thread %d\n", g_var);
    pthread_exit(&g_var);
}

void *mythread2(void *arg)
{
    printf("thread %d %s\n", t.data, t.name);
    pthread_exit(&t);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-05 21:56:28
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{

    strcpy(t.name, "abcdefg");
    t.data = 6;
    sleep(1);
    
    pthread_t thread;
    int ret = pthread_create(&thread, NULL, mythread1, NULL);

    if (ret != 0)
    {
        printf("main thread pthread_create error\n");
    }



    void *p = NULL;
    pthread_join(thread, p);
    printf("main thread %d\n", g_var);

    ret = pthread_create(&thread, NULL, mythread2, NULL);
    if (ret != 0)
    {
        printf("main thread pthread_create error\n");
    }
    printf("main thread %d %s\n", t.data, t.name);

    sleep(2);
    return 0;
}

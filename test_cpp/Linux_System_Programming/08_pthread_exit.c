#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>

pthread_t thread[2];

struct Test
{
    int data;
    char name[64];
};
struct Test t;

void *mythread1(void *arg)
{
    printf("thread1, pid=[%d], id=[%ld]\n", getpid(), pthread_self());
    memset(&t, 0, sizeof(t));
    t.data = 99;
    strcpy(t.name, "xiaoming");
    pthread_exit(&t);
}

void test01()
{
    int ret = pthread_create(&thread[0], NULL, mythread1, NULL);
    if (ret != 0)
    {
        printf("pthread create error [%s]\n", strerror(ret));
        return;
    }
}

int g_var = 9;
void *mythread2(void *arg)
{
    printf("thread2, pid=[%d], id=[%ld]\n", getpid(), pthread_self());
    pthread_exit(&g_var);
}

void test02()
{
    int ret = pthread_create(&thread[1], NULL, mythread2, NULL);
    if (ret != 0)
    {
        printf("pthread create error [%s]\n", strerror(ret));
        return;
    }
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-09 20:29:55
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
    test01();

    test02();

    // pthread_create(pthread_t * thread, const pthread_attr_t *attr,
    //                void *(*start_routine)(void *), void *arg);
    void *p1 = NULL, *p2 = NULL;

    //pthread_join(thread[0], p1);
    //上面的写法会导致崩溃
    pthread_join(thread[0], &p1);
    struct Test * pTmp1 = (struct Test *)p1;
    printf("1111\n");
    printf("%s %d\n", pTmp1->name, pTmp1->data);

    pthread_join(thread[1], &p2);
    int * pTmp2 = (int *)p2;
    printf("%d\n", *pTmp2);

    sleep(2);
    printf("main thread, pid=[%d], id=[%ld]\n", getpid(), pthread_self());

    return 0;
}

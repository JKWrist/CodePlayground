#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX 1000000

struct timeval start;
struct timeval end;
/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-12 10:47:36
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
    char * p = "hello world";

    char str[1024] = {0};

    gettimeofday(&start, NULL);
    // printf("start.tv_sec:%d\n", start.tv_sec);
    // printf("start.tv_usec:%d\n", start.tv_usec);
    for (int i = 0; i < MAX; i++)
    {
        sscanf(p, "%s", str);
        //printf("str %s\n", str);
    }

    gettimeofday(&end, NULL);
    // printf("end.tv_sec:%d\n", end.tv_sec);
    // printf("end.tv_usec:%d\n", end.tv_usec);

    float time_use = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec); //微秒
    printf("test01 time_use is %f\n", time_use);
}

void test02()
{
    char *p = "hello world";

    char str[1024] = {0};

    gettimeofday(&start, NULL);
    // printf("start.tv_sec:%d\n", start.tv_sec);
    // printf("start.tv_usec:%d\n", start.tv_usec);
    for (int i = 0; i < MAX; i++)
    {
        strcpy(str, p);
    }

    gettimeofday(&end, NULL);
    // printf("end.tv_sec:%d\n", end.tv_sec);
    // printf("end.tv_usec:%d\n", end.tv_usec);

    float time_use = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec); //微秒
    printf("test02 time_use is %f\n", time_use);
}

void test03()
{
    float time_use = 0;
    struct timeval start;
    struct timeval end;
    //struct timezone tz; //后面有说明
    gettimeofday(&start, NULL); //gettimeofday(&start,&tz);结果一样
    printf("start.tv_sec:%d\n", start.tv_sec);
    printf("start.tv_usec:%d\n", start.tv_usec);

    sleep(3);
    gettimeofday(&end, NULL);
    printf("end.tv_sec:%d\n", end.tv_sec);
    printf("end.tv_usec:%d\n", end.tv_usec);
    time_use = (end.tv_sec - start.tv_sec) * 1000000 + (end.tv_usec - start.tv_usec); //微秒
    printf("time_use is %f\n", time_use);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-12 10:47:36
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    test01();

    test02();
    
    // test03();

    return 0;
}

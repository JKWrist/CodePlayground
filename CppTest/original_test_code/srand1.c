#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int test1()
{
    //每次运行的结果都相同
}

int test2()
{
    srand(1); //跟例子一的结果完全一样。
}

int test3()
{
    srand(6); //随得的值跟srand(1)不同, 但是每次运行的结果都相同
}

int test4()
{
    srand(time(0)); //指定seed为当前系统流逝了的时间（单位为秒）：time_t time(0)：
}

int main()
{
    //test1();
    //test2();
    //test3();
    test4();
    int ran_num;
    for (int i = 0; i < 10; i++)
    {
        ran_num = rand() % 6;
        printf("ran_num %d\n", ran_num);
    }
    return 0;
}
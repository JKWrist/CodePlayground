#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int test1()
{
    //ÿ�����еĽ������ͬ
}

int test2()
{
    srand(1); //������һ�Ľ����ȫһ����
}

int test3()
{
    srand(6); //��õ�ֵ��srand(1)��ͬ, ����ÿ�����еĽ������ͬ
}

int test4()
{
    srand(time(0)); //ָ��seedΪ��ǰϵͳ�����˵�ʱ�䣨��λΪ�룩��time_t time(0)��
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
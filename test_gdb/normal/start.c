#include<stdio.h>

void test01()
{
    int s = 0;
    for(int i = 1; i <= 1; i++)
    {
        s = i + s;
    }
    printf("%d\n", s);
}

void test02()
{
    int s = 0;
    for(;;)
    {
    	printf("%d\n", s++);
    }
}

int main()
{
	//test01();
	test02();
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *myFunc()
{
    //局部变量a被释放不能操作此空间
    int a = 10;
    return &a;
}

void test01()
{
    int *p = myFunc();
    printf("%d\n", *p); //第一次打印正常只是编译器做了优化
    printf("%d\n", *p); //后面的话不能保证取到的地址是否崩溃
    printf("%d\n", *p);
}

char *getString()
{
    //局部变量str被释放不能操作此空间
    char str[] = "hello world";
    return str;
}

void test02()
{
    char *p = getString();
    printf("p = %s\n", p);
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 14:00:13
*/
int main()
{
    test01();
    test02();
    return 0;
}

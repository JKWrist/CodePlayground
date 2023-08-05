#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、const修饰的变量
//全局变量
const int a = 10;

void test01()
{
    //a = 100; //语法直接失败
    int *p = &a;
    *p = 100; //常量区 ,间接修改 语法通过，运行失败，原因：受到常量区的保护
    printf("%d\n", a);
}

void test02()
{
    const int b = 10;

    //b = 20; //编译中出错

    int *p = &b;
    *p = 100;
    printf("%d\n", *p);
    //在C语言中 const修饰的局部变量  称为伪常量,不可以初始化数组
    int arr[b];
}

//2、字符串常量
void test03()
{
    char * p1 = "hello world";
    char * p2 = "hello world";
    char * p3 = "hello world";

    printf("%p\n", p1);
    printf("%p\n", p2);
    printf("%p\n", p3);
    printf("%p\n", &"hello world");
}

void test04()
{
    char * str = "hello world";  //常量不能修改
    str[0] = 'w';
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 15:47:28
*/
int main()
{
    //test01();
    //test02();
    test03();
    //test04(); 
    return 0;
}

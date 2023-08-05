#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、不能向NULL或者非法内存拷贝数据
void test01()
{
    // char *p = NULL;
    // strcpy(p, "hello world\n"); //Segmentation fault: 11
    // printf("%s", p);

    // char *p2 = 0x11223344;
    // strcpy(p2, "hello world\n"); //Segmentation fault: 11
    // printf("%s", p2);
}

//指针超越变量作用域

int * doWork1()
{
    int a = 1;
    int *p = &a;
    return p;
}

int *doWork2()
{
    //这样写只是为了做测试，不要在项目中这样写，哪里分配空间，哪里释放
    //养成良好的习惯
    int *p = (int *)malloc(sizeof(int) * 1);  
    p[0] = 1;
    printf("doWork2 %p\n", p);
    return p;
}

//2、野指针出现的情况
void test02()
{
    //2.1指针变量未初始化

    // int *p;
    // printf("%d", *p);

    //2.2 指针释放之后未置空
    
    char *str = malloc(100);
    memset(str, 0, 100);
    strcpy(str, "hello");
    free(str);
    str = NULL;
    // printf("%s\n", str);
    // printf("%s\n", str); //str内存没有马上被回收，虽然未发生崩溃，但是存在其他编译器崩溃的可能

    //2.3 空指针可以重复释放、野指针不可以重复释放
    
    //free(str);
    
    /*
    a.out(66397,0x104dc8e00) malloc: *** error for object 0x7fb5d1405890: pointer being freed was not allocated
a.out(66397,0x104dc8e00) malloc: *** set a breakpoint in malloc_error_break to debug
Abort trap: 6
    */

   //2.4指针超越变量作用域

   int * p = doWork1();
   printf("%d\n", *p);
   printf("%d\n", *p);

   p = doWork2();
   printf("%d\n", *p);
   printf("%d\n", *p);
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 16:52:15
*/
int main()
{
    //test01();
    test02();

    return 0;
}

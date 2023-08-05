#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、头文件包含 "" <>区别
// ""包含自定义头文件
// <>包含系统文件

//2、宏 常量
//不重视作用域
//可以利用 undef进行卸载
//宏常量 没有数据类型

//宏 函数
//将短小、频繁使用的函数写成宏函数
//加括号保证运算完整性
//优点， 以空间换时间


//宏常量
void test01()
{

    #define MAX 1024

    //#undef MAX
    //use of undeclared identifier 'MAX'
}

void test02()
{
    printf("%d \n", MAX);
}

//条件编译
#define DEBUG

#ifdef DEBUG
void fun()
{
    printf("debug 版本\n");
}
#else
void fun()
{
    printf("release 版本\n");
}
#endif

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-03 15:38:55
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void doWork(char *p)
{
    if(NULL == p)
    {
        printf("文件 %s  第几行 %d\n", __FILE__, __LINE__);
        printf("日期 %s\n", __DATE__);
        printf("时间 %s\n", __TIME__);

        return;
    }
}

void test03()
{
    doWork(NULL);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-03 15:26:39
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
    //test02();
    test03();

    return 0;
}

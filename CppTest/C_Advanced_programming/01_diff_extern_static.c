#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//static 静态变量
//特点:在运行前分配内存，程序运行结束声明周期结束，在本文件内部都可以使用
static int a = 10;

//在C语言下  全局变量前都隐式加了关键字 extern
extern int g_a = 1000; 

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 15:29:50
*/
int main()
{
   printf("%d %d\n", a, g_a);
   return 0;
}

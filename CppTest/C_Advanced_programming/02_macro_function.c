#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MYADD(x, y) ((x) + (y))
//1、宏函数需要加小括号修饰，保证运算的完整性
//2、通常会将频繁、短小的函数写成宏函数
//3、宏函数会比普通函数在一定程度上效率高，省去入栈出栈的时间开销

void test01()
{
    printf("%d\n", MYADD(4, 6));
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 16:12:54
*/
int main()
{
    test01();
    return 0;
}

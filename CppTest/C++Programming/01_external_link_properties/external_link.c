//C语言下 cosnt 修饰全局变量默认是外部链接属性
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//extern const int g_a;

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-01 20:05:20
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	extern const int g_a;
	printf("g_a = %d\n", g_a);
	return 0;
}

#include <stdio.h>

/****************************************************************
 *  函数名称：do {}while(0)
 *  创建日期：2022-02-08 16:46:28
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
#define DEBUG_1() \
	printf("hello");printf("else\n")

void test01()
{
	if(1)
		printf("hello if\n");
	else
		DEBUG_1();
	printf("---------------------------\n");
}


#define DEBUG_2() \
	do{printf("hello");printf("else\n");}while(0)

void test02()
{
	if(1)
		printf("hello if\n");
	else
		DEBUG_2();
	printf("---------------------------\n");
}


int main()
{
	test01();
	test02();

	return 0;
}

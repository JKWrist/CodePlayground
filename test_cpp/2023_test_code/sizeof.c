#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2023-11-02 10:54:25
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	char p1[] = {"epasdaasdasdsd"};
	printf("p1[] sizeof %d\n", sizeof(p1));
	printf("p1[] strlen %d\n", strlen(p1));

	char *p2 = {"epasdaasdasdsd"};
	printf("*p2 sizeof %d\n", sizeof(p2));
	printf("*p2 strlen %d\n", strlen(p2));

	return 0;
}

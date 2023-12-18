#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01()
{
	const char arr[] = "change uplink dev eth3 to vap50";
	char *p_eth = strstr(arr, "eth");
	char *p_vap = strstr(arr, "vap");

	printf("%p, %p\n", p_eth, p_vap);
	if (p_eth && p_vap)
	{
		if(p_eth < p_vap)
		{
			printf("esaymesh wlan\n");
		}
		else
		{
			printf("esaymesh lan\n");
		}
	}
	else
	{
		printf("not esaymesh\n");
	}
	return 0;
}
/****************************************************************
 *  函数名称：main
 *  创建日期：2023-09-19 18:01:56
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test01();
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01()
{
	char g_arr_filter[2][4] = {"url_filter", "dns_filter"};
	char arr_trans[2][4] = {"tcp", "udp"};
	int arr_network[2] = {4, 6};
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
			printf("%s %d\n", arr_trans[i], arr_network[j]);
	}
	
	// for (int i = 0; i < 2; i++)
	// {
	// 	for (int j = 0; j < 2; j++)
	// 	{
	// 		// hi_sal_iptables_flushchain()
	// 	}
	// }
}
void myFunction(char strArray[][20]) 
{
	int numEntries = 0;
	while (strArray[numEntries][0] != '\0')
	{
		numEntries++;
	}
	// 在这里使用 numEntries 来判断字符串数组共有多少条目
	printf("%d\n", numEntries);
}
void test02()
{
	char strArray[5][20] = {
		"Hello",
		"World",
		"Monica"
	};

	myFunction(strArray);
}
/****************************************************************
 *  函数名称：main
 *  创建日期：2023-09-07 11:39:16
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	// test01();
	test02();
	return 0;
}


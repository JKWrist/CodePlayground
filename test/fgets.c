#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2023-01-12 15:36:43
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	char str_mac_addr[20] = {0};
	int str_mac_len = 20;
	char ipaddr[20] = {0};
	strcpy(ipaddr, "192.168.1.1");

	FILE *pp = NULL;
	int ret = 0;
	char cmd[128] = {0}, *ptr = NULL;

	snprintf(cmd, sizeof(cmd), "ip neigh | grep -F \'%s\' | awk '{print $5}'", ipaddr);
	printf("222bbb %s %s %d\n", __FILE__,  __FUNCTION__, __LINE__);
	pp = popen(cmd, "r");
	printf("222bbb cmd %s %s %s %d\n", cmd, __FILE__,  __FUNCTION__, __LINE__);
	// if (pp)
	// {
	// 	if (fgets(str_mac_addr, str_mac_len, pp))
	// 	{
	// 		ptr = strstr(str_mac_addr, "\n");
	// 		if (ptr)
	// 		{
	// 			*ptr = '\0';
	// 		}
	// 		ret = 1;
	// 	}
	// 	pclose(pp);
	// }

	int length = fgets(str_mac_addr, str_mac_len, pp);
	printf("length %d\n", length);

	if (1 == ret)
	{
		printf("get mac %s\n", str_mac_addr);
	}
	else
	{
		printf("don't get mac\n");
	}

	return ret;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2023-01-09 17:37:42
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	const char arr[][40] = { 
		"Device.WiFi.X_CU_DbhoEnable",
		"Device.WiFi.AccessPoint",
		"Device.WiFi.SSID",
		"Device.WiFi.Radio"
	};

	char str[] = "Device.WiFi.X_CU_DbhoEnable";

	int i, flag = 0;
	for (i = 0; i < 4; ++i)
	{
		if (strncmp(str, arr[i], strlen(arr[i])) == 0)
		{
			flag = 1;
			break;
		}
	}

	if (flag)
	{
		printf("The string matches the element %d in the array.\n", i);
	}
	else
	{
		printf("The string does not match any element in the array.\n");
	}

	return 0;
}

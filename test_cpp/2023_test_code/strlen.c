#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2023-11-16 15:43:07
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	char *p="abcde\n";
	printf("%d\n", strlen(p));

    char subnet_mask[16] = "255.255.255.0";
	
	int decimal = 255;
	int count = 0;
	while (decimal > 0)
	{
		if (decimal % 2 == 1)
		{
			count++;
		}
		decimal /= 2;
	}
    printf("%d\n", count);
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-13 21:33:16
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	FILE * fp = fopen("data.txt", "r");
	
	char buf[1024] = {0};
	fgets(buf, sizeof(buf) - 1, fp);
	printf("buf %s", buf);
	fclose(fp);

	return 0;
}

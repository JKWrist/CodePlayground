#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2023-11-27 17:53:54
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	FILE *fp = fopen("./empty_sem", "r");
	if (NULL == fp)
	{
		return -1;
	}
	char line[16] = {0};
	fgets(line, sizeof(line), fp);
	printf("%d %d\n", strlen(line));
	printf("%s", line);

	line[strlen(line) - 1] = '\0';
	printf("%s\n", line);
	printf("%d %d\n", strlen(line));

	fclose(fp);
	return 0;
}

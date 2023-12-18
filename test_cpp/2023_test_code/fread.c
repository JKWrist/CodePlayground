#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2023-11-07 14:34:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/


/****************************************************************
 *  函数名称：
 *  创建日期：2023-11-07 14:34:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/


/****************************************************************
 *  函数名称：main
 *  创建日期：2023-11-07 14:34:34
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	char * p_filename = "./empty_sem";
	FILE * p_file = fopen(p_filename, "r");
	if (p_file)
	{
		
		int read_size = 0;
		char buffer[4] = {0};
		read_size = fread(buffer, 1, sizeof(buffer) - 1, p_file);

		buffer[read_size] = '\0';
		printf("read_size %d\n", read_size);
		
		if (read_size > 0)
		{
			printf("%d\n", atoi(buffer));
		}
		
		// fgets(buffer, sizeof(buffer), p_file);
		fclose(p_file);
		printf("%d\n", atoi(buffer));
	}
	return 0;
}


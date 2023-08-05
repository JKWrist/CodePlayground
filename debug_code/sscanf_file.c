
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2022-05-13 12:05:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test()
{
	// //写文件
	// FILE* fp_write = NULL;
	// //写方式打开文件
	// fp_write = fopen("./mydata.txt","w");
	// if(fp_write == NULL)
	// {
	// 	perror("fopen:");
	// 	return;
	// }

	// fprintf(fp_write, "hello world:%d!", 10);

	// //关闭文件
	// fclose(fp_write);

	//读文件
	FILE* fp_read = NULL;
	fp_read = fopen("./mydata.txt", "r");
	if(fp_read == NULL)
	{
		perror("fopen:");
		return;
	}

	// char temps[1024]={0};
	// while(!feof(fp_read))
	// {
	// 	fscanf(fp_read,"%s\n", temps);
	// 	printf("%s", temps);
	// }

	int tmp;
	fscanf(fp_read,"%d\n", &tmp);
	printf("%d\n", tmp);

	fclose(fp_read);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-13 12:05:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test();
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	FILE *file;
	char *filename = "/tmp/clean.txt";

	// 判断文件是否存在
	if (access(filename, F_OK) == 0)
	{
		printf("文件已存在\n");
		// 执行相应的操作
	}
	else
	{	
		printf("文件不存在\n");
		// 在满足条件时写入文件
		// 例如：
		file = fopen(filename, "w");
		if (file == NULL)
		{
			printf("无法创建文件\n");
			exit(1);
		}
		fprintf(file, "1\n");
		fclose(file);
		printf("文件已创建并写入内容\n");
	}

	return 0;
}
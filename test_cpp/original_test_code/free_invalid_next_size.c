#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void)
{
	for(int i = 0; i < 100000; i++)
	{
		char *p = NULL;

		// 在堆空间申请 8 字节的内存
		p = malloc(8);

		// 实际使用超过 8 字节
		strncpy(p, "abcd", 128);
		// 可以正常打印
		printf("i = %d, p = %s\n", i, p);

		// 释放内存时会报 invalid next size 错误
		free(p);
	}

	return 0;
}
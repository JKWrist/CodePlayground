#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 100

/****************************************************************
 *  函数名称：
 *  创建日期：2021-10-13 21:01:03
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-13 21:21:28
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
	char buf[BUF_SIZE] = {0};

	int fd = open("data.txt", O_RDONLY);
	if (-1 == read(fd, buf, sizeof(buf) - 1))
	{
		error_handling("read() error");
	}
	printf("file descripter %d, %s\n", fd, buf);
	close(fd);
	return 0;
}

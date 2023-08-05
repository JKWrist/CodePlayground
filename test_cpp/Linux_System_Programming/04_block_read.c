#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-10-18 11:26:06
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main(int argc, char *argv[])
{
	//读取标准输入
	char buf[1024];
	memset(buf, 0x00, sizeof(buf));

	int n = read(STDIN_FILENO, buf, sizeof(buf));
	printf("n == %d, buf -- %s", n, buf);

	return 0;
}

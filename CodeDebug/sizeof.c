

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/****************************************************************
 *  函数名称：main
 *  创建日期：2022-07-06 19:01:47
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	char str[] = "hello world!";
	char *p = str ;
	int n = 10;
	printf("%d\n", sizeof (str));
	printf("%d\n", sizeof (p));
	printf("%d\n", sizeof (n));

	void *p1 = malloc( 100 );
	printf("%d\n", sizeof (p1));

	return 0;
}

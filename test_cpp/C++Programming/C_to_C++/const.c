#include <stdio.h>
int main()
{
	const int n = 10;
	int *p = (int*)&n;  //必须强制类型转换
	*p = 99;  //修改const变量的值
	printf("%d\n", n);
	return 0;
}
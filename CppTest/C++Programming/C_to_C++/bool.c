#include <stdio.h>
int main()
{
	int a, b, flag;
	scanf("%d %d", &a, &b);
	flag = a > b;  //flag保存关系运算结果
	printf("flag = %d\n", flag);
	
	return 0;
}
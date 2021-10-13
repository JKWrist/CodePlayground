#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
	if(a == b)
		return 0;
	return(a > b ? a :b); //比较两个整型数大小,并返回较大值
}

int min(int a,int b)
{
	if(a == b)
		return 0;
	return(a < b ? a :b); //比较两个整型数大小,并返回较小值
}
int (*fun)(int a,int b);

int  main()
{
int *a = (int *)malloc(10 * sizeof(int));
int x;
fun = max;
x = (*fun)(4,5);//x值为5 或者 x = fun(4,5)
printf("min = %d\n", x);
fun = min;
x = (*fun)(4,5);//x值为4 或者 x = fun(4,5)
printf("max = %d\n", x);
}
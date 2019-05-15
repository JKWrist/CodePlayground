#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b)
{
	float * pa = (float *)a;
	float * pb = (float *)b;
	float num1 = *pa;
	float num2 = *pb;
	if (num1 - num2 > 0)
		return 1;
	else
		return -1;
}
//qsort 排序
int main(int argc, char *argv[]) 
{
	float arr[8] = {1.0,2,3.3, 4.0,0,6,7,8};
		qsort(arr, 8, sizeof(float), compare);
		//数组 ， 数组大小， 每个元素大小， 比较函数
	for (int i = 0; i < 8; i++)
	printf("%0.1f ", arr[i]);
}
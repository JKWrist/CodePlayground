#include <stdio.h>

int 	__attribute__ ((weak)) a = 1;
double 	__attribute__ ((weak)) b = 1;

void func()
{
	printf("%s %s: a = %d\n", 	__FILE__, __FUNCTION__, a);
	printf("%s %s: b = %lf\n", 	__FILE__, __FUNCTION__, b);
}
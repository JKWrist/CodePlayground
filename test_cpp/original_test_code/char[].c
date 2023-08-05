#include <stdio.h>

void fun(char * a, int b)
{
	a[0] = 'w';
}

int main(int argc, char *argv[]) 
{
	char a[5] = "asd";
	fun(a, sizeof(a));
	printf("%s\n", a);
}
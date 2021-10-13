#include <stdio.h>

int main(int argc, char *argv[]) 
{
	char * p = "12345567890";
	printf("*p = %s\n", p);
	while(*p != 0)
	{
		*p++;
		printf("*p = %s\n", p);
	}	
	printf("*p = %s\n", p);
	putchar('a');
}
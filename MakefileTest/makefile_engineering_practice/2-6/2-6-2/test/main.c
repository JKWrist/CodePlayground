#include<stdio.h>
#include "dll.h"
#include <string.h>

int main()
{
	printf("hello world!\n");
	
	const char * str = "eeTry not";
	char Target = 'T';

	while(strchr(str, Target))
	{
		printf("Try not has T\n");
	}
	
	dll_init();
	return 0;
}

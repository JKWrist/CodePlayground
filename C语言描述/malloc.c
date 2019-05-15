#include <stdio.h>
#include <stdlib.h>
int g(int ** iptr)
{
	if((*iptr=(int *)malloc(sizeof(int))) == NULL)
		return -1;
	return 0;
}
int main(int argc, char *argv[]) 
{
	int a, *iptr, *jptr, *kptr;
	iptr = &a;
	jptr = iptr;
	kptr = NULL;
	printf("%d\n", g(&jptr));
}
#include <stdio.h>
#include "sort.h"
int facttail(int n, int a)
{
	if(n < 0)
		return 0;
	else if(n == 0)
		return 1;
	else if(n == 1)
		return a;
	else 
		return facttail(n - 1, n * a);
}
int issost(void *data, int size, int esize, int (*compare)(const void *key1, const void *key2))
int main(int argc, char *argv[]) 
{
	printf("%d", facttail(4, 1));	
}
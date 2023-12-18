#include <stdio.h>

int main()
{
	int * a = (int *)malloc(4);
	*a=50;
	printf("%d\n",*a);

	//printf("%d\n",*a);
	return 0;
}
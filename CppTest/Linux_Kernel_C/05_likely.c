#include <stdio.h>

int main()
{
	int a;
	scanf("%d", &a);

	if( unlikely(a==0) )
	//if(a == 0)
	{
		printf("a is 0\n");
	}
	else
	{
		printf("a is not 0\n");	
	}
	return 0;
}
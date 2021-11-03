#include <stdio.h>

int main(int argc, char *argv[]) 
{
	int a = 5;
	int b[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9, 0};
	
	for(int i = 0; i < 10; i++)
	{
		printf("%3d", b[i]);
	}
	printf("\n");
	
	for(int i = 10 - 1; i >= 1; i--)
	{
		if(i > 5)
		{
			continue;
		}
		b[i] = b[i - 1];
		printf("%d\n", i);
	}
	b[0] = 12;
	
	for(int i = 0; i < 10; i++)
	{
		printf("%3d", b[i]);
	}
	printf("\n");
}
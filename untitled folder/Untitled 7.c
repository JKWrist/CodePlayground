#include <stdio.h>

int main() 
{
	int a, n, b;
	int res[20];
	while(scanf("%d%d%d", &a, &n, &b) != EOF)
	{
		int y = 0, product = 1;
		while(n != 0)
		{
			y += (n % 10) * product;
			n = n / 10;
			product *= a; 
		}
		int i = 0;
		do{
			res[i++] = y % b;
			y /= b;
		}while(y != 0);
		
		for(--i; i >= 0; i--)
			printf("%d", res[i]);
		printf("\n");
	}
}

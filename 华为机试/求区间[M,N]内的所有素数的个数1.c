#include <stdio.h>
#include <math.h>
int main()
{
	int a, b, num = 0, i = 0, j, flag;
	scanf("%d%d", &a, &b);
	for (i = a; i <= b; i++)
	{
		flag =1;
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			num++;
	}
	printf("%d", num);
	
}
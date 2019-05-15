#include <stdio.h>
int main()
{
	int a[60];
	int b[60];
	int p1=0,p2=0;
	int i,j;
	for( i = 2;i<= 60;i++)
	{
		int sum = 0;
		for( j  = 1;j<i;j++)
		{
			if(i % j == 0)sum += j;
		}
		if(sum == i)
			a[p1++] = i;
		else if(sum > i)
			b[p2++] = i;
	}
	printf("E: ");
	for( i = 0;i<p1;i++)
		printf("%d ",a[i]);
	printf("G: 2 ");
	for(  i = 0;i<p2;i++)
		printf("%d ",b[i]);
}
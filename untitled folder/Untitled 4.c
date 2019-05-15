#include <stdio.h>
int m[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int s1[100];
int s2[100];

int flag(int y)
{
	
	if((y % 4 == 0 && y % 100 != 0 )|| y % 400 == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int y, n;
	for (int i = 1; i <= 12; i++)
	{
		s1[i] = s1[i - 1] + m[i];
		//printf("%d ", s1[i]);
	}
	m[2] = 29;
	
	for(int i = 1; i <= 12; i++)
		s2[i] = s2[i - 1] + m[i];
	
	while(scanf("%d%d", &y, &n) == 2)
	{
		int i = 1, d;
		if(flag(y))  //是闰年
		{
			while(s2[i] < n)
				i++;
			int d = n - s2[i - 1];
			printf("%d-%02d-%02d\n", y, i, d);
		}
		else  //非闰年
		{
			while(s1[i] < n)
				i++;
			d = n - s1[i - 1];
			printf("%d-%02d-%02d\n", y, i, d);
		}
	}
	
}
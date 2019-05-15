#include <stdio.h>
#include <string.h>
//哈希映射
int main ()
{
	int num = 0;
	int price[100] = {0};
	//memset(price, 0, sizeof(price));
	
	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 4; j++)
			for (int k = 0; k <= 6; k++)
				price[4*i + 5*j + 9*k] = 1;
	
	for (int i =0; i < 100; i++)
		if (price[i] == 1)
			num++;
	printf("%d", num - 1);
}
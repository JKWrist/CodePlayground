#include <stdio.h>
#define N 6 
//五件商品
#define W 21
//最大容量
int B[N][W] = 0;
int w[6] = {0, 2, 3, 4, 5, 8};
int v[6] = {0, 3, 4, 5, 8, 10};

void knapsack()
{
	int k, cap; //k标识第k个商品, cap表示剩下空间
	for (k = 1; k < N; k++)
		for (cap = 1; cap < W; cap++)
		{
			if(w[k] > cap)
			{
				B[k][cap] = B[k-1][cap];
			}
			else
			{
				int value1 = B[k - 1][cap -w[k]] + v[k];
				int value2 = B[k - 1][cap];
				
			}
		}
}
int main(int argc, char *argv[]) 
{
	
}
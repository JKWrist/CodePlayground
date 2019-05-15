#include <stdio.h>

void Bubble(int R[], int n)
{
	int i, j, tmp, flag;
	for (i = n-1; i > 0; i--)
	{
		flag = 0;
		for (j = 1; j <= i; j++)
		{
			if(R[j-1] > R[j])
			{
				tmp = R[j-1];
				R[j-1] = R[j];
				R[j] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		return;
	}
}
int main(int argc, char *argv[]) 
{
	int R[5] = {5, 7, 9, 1, 4};
	Bubble( R, 5);
	for (int i = 0; i < 5; i++)
		printf("%d ",R[i]);
}
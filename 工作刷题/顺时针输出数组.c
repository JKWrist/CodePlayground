#include <stdio.h>
void print(int arr[][], int n)
{
	for(int i = 0; i < n; i++)
	
}
int main(int argc, char *argv[]) 
{
	int arr[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	for (int i = 0;i < 4; i++)
	{	
		for(int j = 0; j < 4; j++)
			printf("%4d", arr[i][j]);
		printf("\n");
	}
}
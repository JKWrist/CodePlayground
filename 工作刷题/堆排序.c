#include <stdio.h>

void heapify(int tree[], int n, int i)
{
	int c1 = 2 * i + 1;
	int c2 = 2 * i + 2;
	int max = i;
	if(c1 < n && tree[c1] > tree[i])
	{
		max = c1;
	}
	if(c2 < n && tree[c2] > tree[max])
		max = c2;
	if(max != i)
	
}
int main(int argc, char *argv[]) 
{
	
}
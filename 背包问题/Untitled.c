#include <stdio.h>

void hanoi(int n, char A, char B, char C) //从A出发绕过B，放到C
{
	if(n == 1)
	{
		printf("%c -> %c\n", A, C);
	}
	else
	{
		hanoi(n-1, A, C, B); //上面的n-1块绕过C 放到B上面
		printf("%c -> %c\n", A, C);
		hanoi(n-1, B, A, C);
	}
}
int main(int argc, char *argv[]) 
{
	hanoi(4, 'A', 'B', 'C');
	return 0;	
}
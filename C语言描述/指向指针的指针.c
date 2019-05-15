#include <stdio.h>
int f(int **iptr)
{
	int a = 10;
	*iptr = &a;
	return 0;
}
int main(int argc, char *argv[]) 
{
	
}
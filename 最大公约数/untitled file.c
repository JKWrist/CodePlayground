#include <stdio.h>

int gcd (int a, int b)
{
	int r = a % b;
	if(r == 0)
		return b;
	else  
		return gcd(b, r);
}
int main(int argc, char *argv[]) 
{
	int a = gcd(26, 100);
	printf("%d", a);
}
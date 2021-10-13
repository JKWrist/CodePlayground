#include <stdlib.h>
#include <stdio.h>
 
int main()
{
	char a[] = "-100";
	char b[] = "123";
	int c;
	c = atoi(a) + atoi(b);
	printf("c = %d\n", c);
	
	printf("%i\n", atoi(" -123junk"));
	printf("%i\n", atoi("0"));
	printf("%i\n", atoi("junk"));         // no conversion can be performed
	printf("%i\n", atoi("2147483648"));   // UB: out of range of int

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
	
	char *val = "abcd efg";
	int len;
	len = strnlen(val, 254);
	printf("%d\n", len);
	return 0;
}

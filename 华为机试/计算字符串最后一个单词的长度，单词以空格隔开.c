#include <stdio.h>
#include <string.h>
void fun(char * array)
{
	char *pnow, *plast;
	pnow = plast = array;
	while (NULL != *(++pnow))
	{
		if (*pnow == ' ')
			plast = pnow + 1; 
	}
	printf("%d\n", strlen(plast));
}
int main()
{
	char a[100];
	while (NULL != gets(a))
	{
		fun(a);
	}
	return 0;
}
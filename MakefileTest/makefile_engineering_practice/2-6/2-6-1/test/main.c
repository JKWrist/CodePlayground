#include<stdio.h>
#include"libmath.h"
int main()
{
	FILE *fp = NULL;
	char buffer[256] = {0}, tmpbuf[3] = {0};
	int count = 0;

	if ( (fp = fopen("makefile", "r")) == NULL)
	{
		return -1;
	}

	while (fgets(buffer, sizeof(buffer), fp) != NULL)
	{
		if(sscanf(buffer, "%s", tmpbuf) != 1)
		{
			continue;
		}
		
		if(count == 0)
		{
			printf("%s", tmpbuf);
		}
		else
		{
			printf(",%s", tmpbuf);
		}
		count++;
	}

	printf("hello world!\n");
	libmath_init();
	return 0;
}

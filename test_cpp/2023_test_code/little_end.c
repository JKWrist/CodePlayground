#include <stdio.h>

int check_sys()
{
	int a = 1;
	return *(char *)&a;
}

int main()
{
	int ret = check_sys();
	if(ret == 1)
	{
		printf("1111\n");
	}
	else
	{
		printf("0000\n");
	}
}

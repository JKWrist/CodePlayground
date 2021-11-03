#include<stdio.h>
int main(void)
{
	FILE *fp;
	fp=fopen("/root/noexitfile","r+");
	if(NULL==fp)
	{
		perror("/root/noexitfile");
	}
	return 0;
}
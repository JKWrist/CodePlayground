#include<stdio.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>

int main(void)
{
	FILE*fp;
	extern int errno;
	char*message;
	if(NULL==(fp=fopen("/dev/dsp","r+")))
	{
		printf("errno=%d\n",errno);
		message=strerror(errno);
		printf("Mesg:%s\n",message);
	}
	exit(0);
}
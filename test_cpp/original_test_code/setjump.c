#include <stdio.h>
#include <setjmp.h>
jmp_buf b;
void f()
{
	longjmp(b, 1);
}
int main(int argc, char *argv[]) 
{
	if(setjmp(b))
	{
		printf("1\n");
	}
	else 
	{
		printf("2\n");
		f();
	}
}
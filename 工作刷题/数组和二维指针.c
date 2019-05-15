#include <stdio.h>
void fun (char **p)
{
	++p;
	printf("%s\n", *p);
	
}

int main(int argc, char *argv[]) 
{
	int a[2][5] = {{1,2,3,4,5}, {6,7,8,9,10}};
	int (*p)[5];
	p = a;
	printf("a[1][2] = %d\n", a[1][2]);
	printf("(*(p+1) + 1) = %d\n", *(*(p+1) + 1));
	char * b[] = {"Morning", "Afternoon", "Evening", "Night"};
		fun(b);
	char str[][10] = {"China", "Beijing"};
	char *c = str;
	printf("%s\n", c+10);
}
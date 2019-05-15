#include <stdio.h>
#include <stdbool.h>
typedef struct stu
{
	int a;
	int b;
	int c;
};
int main(int argc, char *argv[]) 
{
	int n = 10;
	int sum = 1;
	bool flag = false;
	bool a = -1;
	a++;
		printf("%d\n", a);
	a++;
		printf("%d\n", a);
		
	struct stu stu1;
	printf("%lu\n", sizeof(stu1));
	int num = n;
	while(!flag)
	{
		sum = sum * (num--);
		if(num == 1)
		{
			flag = true;
		}
	}
	printf("%d, %d, %d\n",n, sum,  flag);
}
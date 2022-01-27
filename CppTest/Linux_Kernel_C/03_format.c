#include <stdio.h>

void LOG(const char *fmt, ...) __attribute__((format(printf, 1, 2)));

//void test01()
//{
//	LOG("I am xiao hong\n");
//	LOG("I am xiao hong, I have %d head\n", 1);
//	LOG("I am xiao hong, I have %d head, %d arms\n", 1, 2);
//}

void printf_num_test01(int count, ...)
{
	int * args;
	args = &count + 1;
	for(int i = 0; i < count; i++)
	{
		printf("*args: %d\n", *args);
		args++;
	}

}

int main()
{
	//test01();
	printf_num_test01(5, 1, 2, 3, 4, 5);
	return 0;
}

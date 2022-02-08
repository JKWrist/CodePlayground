#include <stdio.h>

static inline 
__attribute__((always_inline)) int func(int a)
{
	return a + 1;
}

static inline void print_num(int a)
{
	printf("%d\n", a);
}

int main(void)
{
	int i;
	i = func(3);
	print_num(10);
	return 0;
}
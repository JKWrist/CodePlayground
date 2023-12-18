#include <stdio.h>

int n[10];//全局变量数组n

int main()
{
 int a[10];//局部变量数组a
 static int b[10];//局部变量数组b
 printf("n[2] = %d\n", n[2]);
 printf("a[2] = %d\n", a[2]);
 printf("b[2] = %d\n", b[2]);
 return 0;
}

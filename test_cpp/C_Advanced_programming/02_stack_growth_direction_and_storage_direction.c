
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1、栈的生长方向
void test01()
{
   int a = 10;
   int b = 10;
   int c = 10;
   int d = 10;

   printf("%p\n", &a); //栈底，高地址
   printf("%p\n", &b);
   printf("%p\n", &c);
   printf("%p\n", &d); //栈顶 低地址
}

//2、内存存放方向
void test02()
{
   int x = 0x11223344;
   char *p = &x;
   printf("%x\n", *p);       //44 低地址，存放低位字节数据
   printf("%x\n", *(p + 1)); //33 高地址， 存放高位字节数据
                             //小端存储方式
}

/*
* Author:xujunze
* Description: 
* Date: Create in 2021-09-04 16:32:13
*/
int main()
{
   //test01();
   test02();

   return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//1��ջ����������
void test01()
{
   int a = 10;
   int b = 10;
   int c = 10;
   int d = 10;

   printf("%p\n", &a); //ջ�ף��ߵ�ַ
   printf("%p\n", &b);
   printf("%p\n", &c);
   printf("%p\n", &d); //ջ�� �͵�ַ
}

//2���ڴ��ŷ���
void test02()
{
   int x = 0x11223344;
   char *p = &x;
   printf("%x\n", *p);       //44 �͵�ַ����ŵ�λ�ֽ�����
   printf("%x\n", *(p + 1)); //33 �ߵ�ַ�� ��Ÿ�λ�ֽ�����
                             //С�˴洢��ʽ
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

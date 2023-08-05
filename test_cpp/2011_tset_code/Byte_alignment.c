#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void test01()
{
	struct A
	{
		int a;
		char b;
		short c;
	};

	struct B
	{
		char b;
		int a;
		short c;
	};

#pragma pack(2) /*指定按2字节对齐*/
	struct C
	{
		char b;
		int a;
		short c;
	};
#pragma pack() /*取消指定对齐，恢复缺省对齐*/

#pragma pack(1) /*指定按1字节对齐*/
	struct D
	{
		char b;
		int a;
		short c;
	};
#pragma pack() /*取消指定对齐，恢复缺省对齐*/

	int s1 = sizeof(struct A);
	int s2 = sizeof(struct B);
	int s3 = sizeof(struct C);
	int s4 = sizeof(struct D);
	printf("%d\n", s1);
	printf("%d\n", s2);
	printf("%d\n", s3);
	printf("%d\n", s4);
}

struct stu
{
	char sex;
	int length;
	char name[10];
} __attribute__((aligned(1)));

void test02()
{
	struct stu my_stu;
	printf("%lu\n", sizeof(my_stu));
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2021-11-17 16:38:33
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	printf("char : %lu short : %lu int : %lu\n", sizeof(char), sizeof(short), sizeof(int));

	test01();

	test02();

	return 0;
}

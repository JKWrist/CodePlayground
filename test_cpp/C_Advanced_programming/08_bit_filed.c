#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/****************************************************************
 *  函数名称：
 *  创建日期：2022-03-02 16:22:17
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	struct bs
	{
		unsigned m;
		unsigned n:4;
		unsigned char ch:6;
	}a = {0xad, 0xE, '$'};

	printf("int %d,short %d,double %d,float %d\n", sizeof(int), sizeof(short), sizeof(double), sizeof(float));
	printf("unsigned %d\n", sizeof(unsigned));
	//printf("%s\n", sizeof(a));

	printf("111 %#x, %#x, %c\n", a.m, a.n, a.ch);
	//printf("111 %d, %d, %d\n", sizeof(a.m), sizeof(a.n), sizeof(a.ch));
	a.m = 0xb8901C456456;
	a.n = 0x2d456;
	a.ch = 'z';

	printf("222 %#x, %#x, %c\n", a.m, a.n, a.ch);
	//printf("222 %d, %d, %d\n", sizeof(a.m), sizeof(a.n), sizeof(a.ch));
}

/****************************************************************
 *  函数名称：位域的存储
 *  创建日期：2022-03-02 16:22:17
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
	// unsigned a;
	// 定义一个无符号、缺省数据类型的变量 a，至于具体的数据类型则取决于编译器的设置。
	// 对于大部分C编译器来说，缺省数据类型是 int，因此这个变量声明相当于
	// unsigned int a;

	struct bs1
	{
		unsigned m:6;
		unsigned n:12;
		unsigned p:4;
	};

	struct bs2
	{
		unsigned m:6,
				 n:12,
				 p:22;   //此处修改为22
	};

	struct bs3
	{
		unsigned m :12;
		unsigned char ch: 4;
		unsigned p:4;
	};

	struct bs4
	{
		unsigned m : 13;
		unsigned ch;
		unsigned p : 4;
	};

	printf("bs1 %d\n", sizeof(struct bs1));
	printf("bs2 %d\n", sizeof(struct bs2));
	printf("bs3 %d\n", sizeof(struct bs3));
	printf("bs4 %d\n", sizeof(struct bs4));
}

/****************************************************************
 *  函数名称：无名位域
 *  创建日期：2022-03-02 16:54:41
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test03()
{
	struct bs
	{
		int m:12;
		int  :12;//该位域成员不可用
		int n:8;
	};
	printf("bs %d\n", sizeof(struct bs));
}


/****************************************************************
 *  函数名称：main
 *  创建日期：2022-03-02 16:22:17
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	//test01();
	//test02();
	test03();

	return 0;
}

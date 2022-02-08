#include <stdio.h>

/****************************************************************
 *  函数名称：返回 函数返回地址
 *  创建日期：2022-02-08 11:22:28
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void f1(void)
{
	int *p;
	p = __builtin_return_address(0);
	printf("f1 return address : %p\n", p);

	p = __builtin_return_address(1);
	printf("fun1 return address : %p\n", p);

	p = __builtin_return_address(2);
	printf("test01 return address : %p\n", p);
	printf("---------------------------\n");
}

void func1(void)
{
	int *p;
	p = __builtin_return_address(0);
	printf("fun1 return address %p\n", p);

	p = __builtin_return_address(1);
	printf("test01 return address %p\n", p);
	printf("---------------------------\n");

	f1();
}

void test01()
{
	int *p;
	p = __builtin_return_address(0);
	printf("test01 return address %p\n", p);
	printf("---------------------------\n");
	
	func1();

	printf("goodbye!\n");
	printf("---------------------------\n");
}

/****************************************************************
 *  函数名称：返回 函数栈帧地址
 *  创建日期：2022-02-08 11:22:55
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void func2(void)
{
	int *p;
	p = __builtin_frame_address(0);
	printf("func2 frame : %p\n", p);

	p = __builtin_frame_address(0);
	printf("test02 frame : %p\n", p);
	printf("---------------------------\n");
}

void test02()
{
	int *p;
	p = __builtin_frame_address(0);
	printf("test02 frame : %p\n", p);
	printf("---------------------------\n");

	func2();
}

/****************************************************************
 *  函数名称：C标准库的内建函数 __built_memcpy 、__built_memset、__built_memcmp
 *  创建日期：2022-02-08 11:33:38
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test03()
{
	char str[100];
	__builtin_memcpy(str, "hello world!", 20);
	__builtin_printf("%s\n", str);
	printf("---------------------------\n");
}

/****************************************************************
 *  函数名称：__builtin_constant_p(n)
 *  创建日期：2022-02-08 11:45:20
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test04()
{
	int const  a = 10;
	if(__builtin_constant_p(a))
	{
		printf("const int\n");
	}
	else
	{
		printf("not const int\n");
	}

	char * pstr = "你好 世界";
	if(__builtin_constant_p(a))
	{
		printf("const str\n");
	}
	else
	{
		printf("not const str\n");
	}
	printf("---------------------------\n");
}

/****************************************************************
 *  函数名称：__buildin_expect(exp, c)
 *  创建日期：2022-02-08 11:51:14
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test05()
{
	int a;
	a = __builtin_expect(3,1);
	printf("a = %d\n", a);
	a = __builtin_expect(3,10);
	printf("a = %d\n", a);
	a = __builtin_expect(3,100);
	printf("a = %d\n", a);
	printf("---------------------------\n");
}

int main()
{
	//test01();
	test02();
	test03();
	test04();
	test05();


	return 0;
}
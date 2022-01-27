#include <stdio.h>

/****************************************************************
 *  函数名称：数组初始化
 *  创建日期：2022-01-27 15:56:22
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int b[100] = {[9] = 10, [19] = 20};
int c[100] = {[10 ... 30] = 10, [70 ... 80] = 20};
void test01()
{
	//数组初始化
	for (int i = 0; i < 10; i++) 
	{
		printf("a[%d] = %d\n", i, a[i]);
	}
	printf("---------------------------\n");
	//数组范围初始化
	for (int i = 0; i < 100; i++) 
	{
		printf("%d ", b[i]);
		if(0 == (i + 1) % 10)
		{
			printf("\n");
		}
	}
	printf("---------------------------\n");
	//数组指定元素范围进行初始化
	for (int i = 0; i < 100; i++) 
	{
		printf("%d ", c[i]);
		if(0 == (i + 1) % 10)
		{
			printf("\n");
		}
	}
	printf("---------------------------\n");
}

/****************************************************************
 *  函数名称：...范围扩展在switch中的应用
 *  创建日期：2022-01-27 16:16:53
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
	int i = 4;
	switch(i)
	{
		case 1:
			printf("1\n");
			break;
		case 2 ... 8:
			printf("2-8\n");
			break;
		case 9:
			printf("9\n");
			break;
		case 10:
			printf("10\n");
			break;
	}
}

/****************************************************************
 *  函数名称：结构体初始化
 *  创建日期：2022-01-27 16:02:10
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
struct student 
{
  char name[20];
  int age;
};

void test03()
{
	struct student st1 = {"xiaobai", 20};

	struct student st2 = {
			.name = "xiaohong",
			.age = 2,
	};

	printf("%s %d \n", st1.name, st1.age);
	printf("%s %d \n", st2.name, st2.age);
	printf("---------------------------\n");
}

int main()
{
	test01();
	test02();
	test03();
	return 0;
}
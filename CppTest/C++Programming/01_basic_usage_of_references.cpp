//引用的基本用法

#include <iostream>

using namespace std;

//1、引用的基本用法  类型 &别名 = 原名
void test01()
{
	cout << "-------" << "1" << "-------" << endl;
	int a =10;
	int &b = a;

	b = 100;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

void test02()
{
	cout << "-------" << "2" << "-------" << endl;
	int a = 100;
	//int & b; //引用的使用必须初始化

	int & b = a;

	int c = 200;
	b = c;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << b << endl;
}

//对数组建立引用
void test03()
{
	cout << "-------" << "3" << "-------" << endl;

	//1、直接建立引用
	int arr[10] = {0};
	int (& pArr)[10] = arr;
	for(int i = 0; i < 10; i++)
	{
		arr[i] = i;
	}

	for(int i = 0; i < 10; i++)
	{
		cout << "arr[i] = " << arr[i] << endl;
	}

	cout << endl;
	
	for(int i = 0; i < 10; i++)
	{
		cout << "pArr[i] = " << pArr[i] << endl;
	}

	cout << endl;

	//2、先定义出数组类型，再通过类型定义引用
	typedef int(ARRTYPE)[10];

	ARRTYPE & pArr2 = arr;
	for(int i = 0; i < 10; i++)
	{
		cout << "pArr2[i] = " << pArr[i] << endl;
	}

}

int main()
{
	test01();

	test02();

	test03();
}
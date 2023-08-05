//静态成员
#include <iostream>
using namespace std;

class Person
{
public:
	//1、静态成员变量
	//静态成员变量：编译阶段就分配了内存
	//类内声明，类外初始化
	//静态成员变量，所有对象都共享同一份数据
	static int m_A;

	//2、静态成员函数
	//所有对象都共享同一个func函数
	static void func()
	{
		
	}

	int m_C;

private:
	static int m_B;  //私有静态成员变量
	static void func2()
	{

	}
};

int Person::m_A = 0;
int Person::m_B = 0;

//访问成员变量
void test01()
{
	//1、通过对象进行访问
	Person p1;
	cout << p1.m_A << endl;

	Person p2;
	p2.m_A = 100;
	cout << p1.m_A << endl;
	
	//2、通过类型进行访问
	cout << Person::m_A << endl;

	//静态成员变量，也是有访问权限的，私有权限类外访问不到
	//cout << Person::m_B << endl;
}

//访问成员函数
void test02()
{
	//通过对象
	Person p1;
	p1.func();

	//通过类名
	Person::func();

	//静态成员函数也是有访问权限的
	//Person::func2();  //'func2' is a private member of 'Person'
}

int main()
{
	test01();
	test02();

	return 0;
}
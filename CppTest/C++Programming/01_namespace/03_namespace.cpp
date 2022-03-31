#include <iostream>
using namespace std;

#include "game1.h"
#include "game2.h"

//1、命名空间用途，解决名称冲突
void test01()
{
	KingGlory::goAtk();
	LOL::goAtk();
	cout << "---------------------------" << endl;
}

//2、命名空间下 可以放 变量、函数、结构体、类
namespace A
{
	int m_A;
	void func();
	struct Person
	{};

	class Animal
	{};
}

//3、命名空间 必须要声明在全局作用域下
void test02()
{
	//不可以命名到局部作用域
	//namesapce B{}
	cout << "---------------------------" << endl;
}

//4、命名空间可以嵌套命名空间
namespace B
{
	int m_A = 10;
	namespace C
	{
		int m_A = 20;
	}
}

void test03()
{
	cout << "B空间下的 m_A = " << B::m_A << endl;
	cout << "C空间下的 m_A = " << B::C::m_A << endl;
	cout << "---------------------------" << endl;
}

//命名空间是开放的，可以随时给命名空间添加新的成员
namespace B
{
	int m_B = 100;
}

void test04()
{
	cout << "B空间下的 m_A = " << B::m_A << endl;
	cout << "B空间下的 m_B = " << B::m_B << endl;
	cout << "---------------------------" << endl;
}

int main()
{
	test01();
	test02();
	test03();
	test04();
}
//构造函数的调用规则

#include <iostream>
#include <string>

using namespace std;


//1、编译器会给一个类 至少增加三个函数 默认构造(空实现)，拷贝构造（值拷贝），析构函数（空实现）
//2、如果我们提供了有参构造函数，编译器就不会提供默认构造函数，但是依然会提供拷贝构造函数
//3、如果我们自己提供了 拷贝构造函数，编译器就不会提供其他构造函数
class Person
{
public:
	Person()
	{
		cout << "默认构造函数调用" << endl;
	}

	Person(int age)
	{
		m_Age = age;
		cout << "有参构造函数调用" << endl;
	}

	Person(const Person &p)
	{
		m_Age = p.m_Age;
		cout << "拷贝构造函数调用" << endl;
	}

	~Person()
	{
		cout << "析构函数" << endl;
	}
	int m_Age;
};

void test01()
{
	Person p;
	p.m_Age = 20;

	Person p2(p);
	cout << "p2的年龄为: " << p2.m_Age << endl;
}

int main()
{
	test01();

	return 0;
}
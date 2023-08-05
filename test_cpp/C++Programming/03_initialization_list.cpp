//初始化列表

#include <iostream>
using namespace std;

class Person
{
public:
	// Person(int a, int b, int c)
	// {
	// 	m_A = a;
	// 	m_B = b;
	// 	m_C = c;
	// }

	//构造函数名称后， 属性，值。 属性，值
	Person(int a, int b, int c)
	:m_A(a), 
	 m_B(b),
	 m_C(c)
	{

	}

	int m_A;
	int m_B;
	int m_C;
};


void test01()
{
	Person p(10, 20, 30);
	cout << p.m_A << endl;
	cout << p.m_B << endl;
	cout << p.m_C << endl;
}

int main()
{
	test01();

	return 0;
}
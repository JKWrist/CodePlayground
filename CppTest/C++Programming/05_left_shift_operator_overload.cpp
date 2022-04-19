#include <iostream>
using namespace std;

class Person
{
public:
	friend ostream& operator<<(ostream &cout, Person &p1);

	Person(int a, int b)
	{
		m_A = a;
		m_B = b;
	}

	//视图利用成员函数 做<<重载
	// void operator<<(Person & p)  //p.operator<<(cout)   p<<cout 这个行为不符合我们的操作习惯
	// {
	// }

private:
	int m_A;
	int m_B;
};

//利用全局函数 实现左移运算符的重载
ostream& operator<<(ostream & cout, Person & p)
{
	cout << "m_A " << p.m_A << " m_B " << p.m_B;
	return cout;
}

void test01()
{
	Person p1(10, 10);
	cout << p1 << endl;
}

int main()
{
	test01();

	return 0;
}
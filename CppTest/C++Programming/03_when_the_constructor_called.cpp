#include <iostream>

using namespace std;

class Person
{
public:
	Person()
	{
		cout << "Person 的默认构造函数调用" << endl;
	}

	Person(int age)
	{
		cout << "Person 的有参构造函数调用" << endl;
		m_Age = age;
	}

	//拷贝构造函数
	Person(const Person & p)
	{
		cout << "Person 的拷贝构造函数调用" << endl;
		m_Age = p.m_Age;
	}

	//析构函数
	~Person()
	{
		cout << "Person 的析构函数调用" << endl;
	}

	int m_Age;
};

//1、用已经创建好的对象聊初始化新的对象
void test01()
{
	Person p1(18);
	Person p2 = Person(p1);
	cout << "p2 的年龄 " << p2.m_Age << endl;
}


//2、值传递的方式给函数参数传值
void doWork(Person p)
{

}
void test02()
{
	Person p1;
	doWork(p1);
}

//以值的方式，返回局部对象
Person doWork2()
{
	Person p;
	return p;
}

void test03()
{
	Person p = doWork2();
}
/*	
	编译器优化代码后 release版本代码类似以下：
	void doWork2( Person &p ){};

	Person p;
	doWork2(p);

	实际上只有一个 Person 的默认构造函数调用 和 Person 的析构函数调用
*/

int main()
{
	//test01();
	//test02();

	test03();

	return 0;
}
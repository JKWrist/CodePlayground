//构造函数的分类以及调用

#include <iostream>
using namespace std;

//构造函数的分类
//按照参数分类：无参构造（默认构造函数），有参构造
//按照类型分类：普通构造函数，拷贝构造函数

class Person
{
public:
	Person()
	{
		cout << "Person 默认构造函数调用" << endl;
	}

	Person(int age)
	{
		m_Age = age;
		cout << "Person 有参构造函数调用" << endl;
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
		cout << "Person 析构函数调用"  << endl;
	}
	int m_Age;
};

//构造函数的调用
void test01()
{
	Person p;
	
	//1、括号法
	Person p1(10);
	Person p2(p);
	Person p3();

	cout << "--------------------------" << endl;
	//注意事项一
	//不要用括号法 调用无参构造函数 p3;编译器认为 代码是函数的声明
}

void test02()
{
	Person p;
	//2、显示法
	Person p4 = Person(10);  //有参构造
	Person p5 = Person(p);	//拷贝构造

	Person(10); //匿名对象 特点：当前行执行完后，立即释放
	//Person(p4);
	
	cout << "--------------------------" << endl;

	//注意事项二
	//不要用拷贝构造函数初始化匿名对象，Person(p4); 
	//编译器认为 Person p4对象实例化，如果已经有p4 p4就重定义
}

void tset03()
{
	//隐式法
	Person p5 = 10;
	Person p6 = p5;
	cout << "--------------------------" << endl;
}

int main()
{
	//test01();
	test02();
	return 0;
}
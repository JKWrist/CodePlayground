//const 分配内存情况

#include <iostream>
#include <string>

using namespace std;

//1、对const变量 取地址。会分配临时内存
void test01()
{
	const int a = 10;
	int * p = (int *)&a;
	*p = 20;

	cout << "a = " << a << " *p = " << *p << endl;
}

//2、使用普通变量 初始化 const变量
void test02()
{
	int a = 10;
	const int b = a;

	cout << "b = " << b << endl;
}

//3、对于自定义数据类型
struct Person
{
	string name;
	int age;
};

void test03()
{
	const Person p = {};
	//p.m_Name = "abcdef";
	Person * pp = (Person *) &p;
	
	pp->name = "abcdefg";
	pp->age = 18;

	cout << p.name << " " << p.age << endl;
	cout << pp->name << " " << pp->age << endl;
}

int main()
{
	test01();
	test02();
	test03();

}

//类模板函数成员的类外实现

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

template<class T1, class T2>
class Person
{
public:
	Person(T1 name, T2 age);
	// {
	// 	this->m_Name = name;
	// 	this->m_Age = age;
	// }
	void showPerson();
	// {
	// 	cout << "姓名： " << this->m_Name << " 年龄：" << this->m_Age << endl;
	// }
	T1 m_Name;
	T2 m_Age;
};


template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age)
{
	this->m_Name = name;
	this->m_Age = age;
}

template<class T1, class T2>
void Person<T1, T2>::showPerson()
{
	cout << "姓名： " << this->m_Name << " 年龄：" << this->m_Age << endl;
}

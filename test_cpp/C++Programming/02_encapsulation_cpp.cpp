#include <iostream>
#include <string>
using namespace std;

struct Person
{
	//公共权限
public:
	void PersonEat()
	{
		printf("%s 在吃人饭\n", m_Name.c_str());
	}
	string m_Name;
	int m_Age;
};


struct Dog
{
	//公共权限
public:
	void DogEat()
	{
		printf("%s 在吃狗粮\n", m_Name.c_str());
	}

	string m_Name;
	int m_Age;
};

//C++封装 理念， 将属性和行为作为一个整体，来表现生活中的事物
			//  将属性和行为就以权限进行控制

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-07 20:18:50
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	struct Person p;
	p.m_Name = "老王";
	p.m_Age = 30;

	p.PersonEat();

	//p.DogEat();
}


// struct 与 class 区别？
// class 默认权限是私有权限，struct 默认权限是公共权限
// 访问权限
// public		公共权限 成员变量类内，类外都可以访问	
// private		私有权限 成员变量在类内可以访问，类外不可以访问，儿子不可以继承父亲的 private权限内容
// protected	保护权限 成员变量在类内可以访问，类外不可以访问，儿子不可以继承父亲的 protected权限内容

class Person2
{
public:
	string m_Name;
protected:
	string m_Car;
private:
	string m_Pwd;

public:
	void func()
	{
		m_Name	= "张三";
		m_Car 	= "劳斯莱斯";
		m_Pwd	= "123456";
 
		cout << m_Name << m_Car << m_Pwd << endl;
	}
};

void test02()
{
	Person2 p2;
	p2.m_Name = "李四";
	//p2.m_Car = "比亚迪";
	//p2.m_Pwd = "456";
	p2.func();
}

int main()
{
	test01();
	test02();

	return 0;
}
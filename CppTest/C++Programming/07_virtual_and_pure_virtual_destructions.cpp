//虚函数指针，验证对象中的虚指针
//多态
//虚析构与纯虚析构函数
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class A
{
public:
	virtual void func1(){}
	virtual void func2(){}
};

//B类为空，那么大小应该是1字节，实际情况是这样吗？
class B : public A
{

};

//验证对象中的虚指针
void test01()
{
	cout << "A size:" << sizeof(A) << endl;
	cout << "B size:" << sizeof(B) << endl;
}

/****************************************************************
 *  函数名称：抽象类,里面至少有一个纯虚函数
 *  创建日期：2022-05-04 21:37:52
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
//抽象制作饮品
class AbstractDrinking
{
public:
	//烧水
	virtual void Boil() = 0;
	//冲泡
	virtual void Brew() = 0;
	//倒入杯中
	virtual void PourInCup() = 0;
	//加入辅料
	virtual void PutSomething() = 0;
	//规定流程
	void MakeDrink(){
		Boil();
		Brew();
		PourInCup();
		PutSomething();
	}
};

//制作咖啡
class Coffee : public AbstractDrinking
{
public:
	//烧水
	virtual void Boil(){
		cout << "煮农夫山泉!" << endl;
	}
	//冲泡
	virtual void Brew(){
		cout << "冲泡咖啡!" << endl;
	}
	//倒入杯中
	virtual void PourInCup(){
		cout << "将咖啡倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething(){
		cout << "加入牛奶!" << endl;
	}
};

//制作茶水
class Tea : public AbstractDrinking
{
public:
	//烧水
	virtual void Boil(){
		cout << "煮自来水!" << endl;
	}
	//冲泡
	virtual void Brew(){
		cout << "冲泡茶叶!" << endl;
	}
	//倒入杯中
	virtual void PourInCup(){
		cout << "将茶水倒入杯中!" << endl;
	}
	//加入辅料
	virtual void PutSomething(){
		cout << "加入食盐!" << endl;
	}
};

//业务函数
void DoBussiness(AbstractDrinking* drink)
{
	drink->MakeDrink();
	delete drink;
}

void test02()
{
	DoBussiness(new Coffee);
	cout << "--------------" << endl;
	DoBussiness(new Tea);
}


/****************************************************************
 *  函数名称：
 *  创建日期：2022-05-04 21:45:15
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
class Animal
{
public:
	Animal()
	{
		cout << "Animal的构造函数调用" << endl;
	}
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}
	//如果子类中有指向堆区的属性，那么要利用虚析构技术在delete的时候，调用子类的析构函数
	//virtual ~Animal()
	// {
	// 	cout << "Animal的析构函数调用" << endl;
	// }

	//纯虚析构 需要有声明 也需要有实现
	virtual ~Animal() = 0;
};

Animal::~Animal()
{
// 	Undefined symbols for architecture x86_64:
//   "Animal::~Animal()", referenced from:
//       Cat::Cat(char*) in 07_virtual_and_pure_virtual_destructions-b8eadb.o
//       Cat::~Cat() in 07_virtual_and_pure_virtual_destructions-b8eadb.o
// ld: symbol(s) not found for architecture x86_64
	cout << "Animal的纯析构函数调用" << endl;
}

class Cat : public Animal
{
public:
	Cat(char * name)
	{
		cout << "Cat的构造函数调用" << endl;
		this->m_Name = new char[strlen(name) + 1];
		strcpy(this->m_Name, name);
	}

	virtual void speak()
	{
		cout << "小猫" << m_Name << "在说话" << endl;
	}

	~Cat()
	{
		if(m_Name)
		{
			cout << "Cat的析构函数调用" << endl;
			delete[] m_Name;
			m_Name = NULL;
		}
	}

	char * m_Name;
};

void test03()
{
	Animal * animal = new Cat("Tom");
	animal->speak();
	delete animal;
}

int main()
{
	//test01();
	//test02();
	test03();

	return 0;
}
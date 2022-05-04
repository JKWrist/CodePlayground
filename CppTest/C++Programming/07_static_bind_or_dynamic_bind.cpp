//静态联编与动态联编
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Animal
{
public:
	virtual void speak()
	{
		cout << "动物在说话" << endl;
	}

	virtual void eat()
	{
		cout << "动物在吃饭" << endl;
	}
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "小猫在说话" << endl;
	}
	void eat()
	{
		cout << "小猫在吃饭" << endl;
	}
};

class Dog : public Animal
{
public:
	void speak()
	{
		cout << "小狗在说话" << endl;
	}
};


//动态多态产生的条件
//1、先有继承关系
//2、父类中有虚函数。子类重写父类中的虚函数
//3、父类的指针或引用 指向子类的对象

//对于父类关系的两个类， 指针或者引用是可以直接转换的
void doSpeak(Animal & animal) //Animal & animal = cat;
{
	//如果地址早就绑定好了，地址早绑定，是可以直接转换的
	//如果想调用小猫说话，这个时候函数的地址就不能早就绑定好，而是在运行阶段再去绑定函数地址，属于地址晚绑定，交动态联编
	animal.speak();
}

void test01()
{
	Cat cat;
	doSpeak(cat);

	Dog dog;
	doSpeak(dog);
}

void test02()
{
	cout << "sizeof(Animal) = " << sizeof(Animal) << endl;
	Animal * animal = new Cat;
	animal->speak();
	
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-04 16:15:47
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test01();
	test02();

	return 0;
}

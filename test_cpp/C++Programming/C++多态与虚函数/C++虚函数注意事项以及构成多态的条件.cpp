//C++ 虚函数对于多态具有决定性的作用，有虚函数才能构成多态。上节《C++多态和虚函数快速入门教程》我们已经介绍了虚函数的概念，这节我们来重点说一下虚函数的注意事项。

//1) 只需要在虚函数的声明处加上 virtual 关键字，函数定义处可以加也可以不加。
//
//2) 为了方便，你可以只将基类中的函数声明为虚函数，这样所有派生类中具有遮蔽关系的同名函数都将自动成为虚函数。关于名字遮蔽已在《C++继承时的名字遮蔽》一节中进行了讲解。
//
//3) 当在基类中定义了虚函数时，如果派生类没有定义新的函数来遮蔽此函数，那么将使用基类的虚函数。
//
//4) 只有派生类的虚函数覆盖基类的虚函数（函数原型相同）才能构成多态（通过基类指针访问派生类函数）。例如基类虚函数的原型为virtual void func();，派生类虚函数的原型为virtual void func(int);，那么当基类指针 p 指向派生类对象时，语句p -> func(100);将会出错，而语句p -> func();将调用基类的函数。
//
//5) 构造函数不能是虚函数。对于基类的构造函数，它仅仅是在派生类构造函数中被调用，这种机制不同于继承。也就是说，派生类不继承基类的构造函数，将构造函数声明为虚函数没有什么意义。
//
//6) 析构函数可以声明为虚函数，而且有时候必须要声明为虚函数

#include <iostream>
using namespace std;
//基类People
class People
{
public:
	People(char *name, int age);
	virtual void display();
protected:
	char *m_name;
	int m_age;
};
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display()
{
	cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}

//派生类Teacher
class Teacher: public People
{
public:
	Teacher(char *name, int age, int salary);
	void display();
private:
	int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}

void Teacher::display()
{
	cout<<m_name<<"今年"<<m_age<<"岁了，是一名教师，每月有"<<m_salary<<"元的收入。"<<endl;
}

int main()
{
	People *p = new People("王志刚", 23);
	p -> display();
	p = new Teacher("赵宏佳", 45, 8200);
	p -> display();
	return 0;
}
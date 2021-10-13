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
void People::display(){
	cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}


//派生类Teacher
class Teacher: public People
{
public:
	Teacher(char *name, int age, int salary);
//有了虚函数，基类指针指向基类对象时就使用基类的成员（包括成员函数和成员变量），指向派生类对象时就使用派生类的成员。换句话说，基类指针可以按照基类的方式来做事，也可以按照派生类的方式来做事，它有多种形态，或者说有多种表现方式，我们将这种现象称为多态（Polymorphism）
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

//int main()
//{
//	People p("王志刚", 23);
//	Teacher t("赵宏佳", 45, 8200);
//
//	People &rp = p;
//	People &rt = t;
//
//	rp.display();
//	rt.display();
//	return 0;
//}
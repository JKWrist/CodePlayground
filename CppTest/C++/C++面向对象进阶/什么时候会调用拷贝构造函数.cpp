//int a = 100;  //以赋值的方式初始化
//a = 200;  //赋值
//a = 300;  //赋值
//int b;  //默认初始化
//b = 29;  //赋值
//b = 39;  //赋值

#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	Student(string name = "", int age = 0, float score = 0.0f);  //普通构造函数
	Student(const Student &stu);  //拷贝构造函数
public:
	Student & operator=(const Student &stu);  //重载=运算符
	void display();
private:
	string m_name;
	int m_age;
	float m_score;
};
Student::Student(string name, int age, float score): m_name(name), m_age(age), m_score(score)
{ 

}


//拷贝构造函数
Student::Student(const Student &stu)
{
	this->m_name = stu.m_name;
	this->m_age = stu.m_age;
	this->m_score = stu.m_score;
	cout<<"Copy constructor was called."<<endl;
}

//重载=运算符
Student & Student::operator=(const Student &stu)
{
	this->m_name = stu.m_name;
	this->m_age = stu.m_age;
	this->m_score = stu.m_score;
	cout<<"operator=() was called."<<endl;
   
	return *this;
}

void Student::display()
{
	cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}

void func(Student s)
{
	//TODO:
}

Student func1()
{
	Student s("小明", 16, 90.5);
	return s;
}

int main()
{
	//stu1、stu2、stu3都会调用普通构造函数Student(string name, int age, float score)
//	Student stu1("小明", 16, 90.5);
//	Student stu2("王城", 17, 89.0);
//	Student stu3("陈晗", 18, 98.0);
//   
//	Student stu4 = stu1;  //调用拷贝构造函数Student(const Student &stu)
//	stu4 = stu2;  //调用operator=()
//	stu4 = stu3;  //调用operator=()
//   
//	Student stu5;  //调用普通构造函数Student()
//	stu5 = stu1;  //调用operator=()
//	stu5 = stu2;  //调用operator=()
	
	
//	Student stu("小明", 16, 90.5);  //普通初始化
//	func(stu);  //以拷贝的方式初始化
	
	Student stu = func1();
   //现代编译器上，只会调用一次拷贝构造函数，或者一次也不调用，例如在 VS2010 下会调用一次拷贝构造函数，在 GCC、Xcode 下一次也不会调用。这是因为:现代编译器都支持返回值优化技术，会尽量避免拷贝对象，以提高程序运行效率。关于编译器如何实现返回值优化的我们不再展开讨论，有兴趣的读者请猛击：
	return 0;
}
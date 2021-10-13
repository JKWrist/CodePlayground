#include <iostream>
#include <string>
using namespace std;
class Student
{
public:
	Student(string name = "", int age = 0, float score = 0.0f);  //普通构造函数
	Student(const Student &stu);  //拷贝构造函数（声明）
public:
	void display();
private:
	string m_name;
	int m_age;
	float m_score;
};

Student::Student(string name, int age, float score)
: m_name(name)
, m_age(age)
, m_score(score)
{

}

//拷贝构造函数（定义）
//拷贝构造函数只有一个参数，它的类型是当前类的引用，而且一般都是 const 引用。

//1) 为什么必须是当前类的引用呢？
//如果拷贝构造函数的参数不是当前类的引用，而是当前类的对象，那么在调用拷贝构造函数时，会将另外一个对象直接传递给形参，这本身就是一次拷贝，会再次调用拷贝构造函数，然后又将一个对象直接传递给了形参，将继续调用拷贝构造函数……这个过程会一直持续下去，没有尽头，陷入死循环。
//
//只有当参数是当前类的引用时，才不会导致再次调用拷贝构造函数，这不仅是逻辑上的要求，也是 C++ 语法的要求。
//2) 为什么是 const 引用呢？
//拷贝构造函数的目的是用其它对象的数据来初始化当前对象，并没有期望更改其它对象的数据，添加 const 限制后，这个含义更加明确了。
//
//另外一个原因是，添加 const 限制后，可以将 const 对象和非 const 对象传递给形参了，因为非 const 类型可以转换为 const 类型。如果没有 const 限制，就不能将 const 对象传递给形参，因为 const 类型不能转换为非 const 类型，这就意味着，不能使用 const 对象来初始化当前对象了。

Student::Student(const Student &stu)
{
	this->m_name = stu.m_name;
	this->m_age = stu.m_age;
	this->m_score = stu.m_score;
	cout << "Copy constructor was called." << endl;
}


void Student::display()
{
	cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<endl;
}


int main()
{
	cout << "111" << endl;
	Student stu1("小明", 16, 90.5);
	
	cout << "222" << endl;
	Student stu2 = stu1;  //调用拷贝构造函数
	
	cout << "333" << endl;
	Student stu3(stu1);  //调用拷贝构造函数
	
	stu1.display();
	stu2.display();
	stu3.display();

	return 0;
}
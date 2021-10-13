#include <iostream>
using namespace std;
class Student
{
public:
	void setname(char *name);
	void setage(int age);
	void setscore(float score);
	void show();
	void printThis();
private:
	char *name;
	int age;
	float score;
};

void Student::setname(char *name)
{
	this->name = name;
}

void Student::setage(int age)
{
	this->age = age;
}

void Student::setscore(float score)
{
	this->score = score;
}

void Student::show()
{
	//this 只能用在类的内部，通过 this 可以访问类的所有成员，包括 private、protected、public 属性的。
	cout << this->name
	     << "的年龄是" 
		 << this->age
		 << "，成绩是"
		 << this->score
		 <<endl;
}

void Student::printThis()
{
	cout << this << endl;
}


//this 是 const 指针，它的值是不能被修改的，一切企图修改该指针的操作，如赋值、递增、递减等都是不允许的。
//this 只能在成员函数内部使用，用在其他地方没有意义，也是非法的。
//只有当对象被创建后 this 才有意义，因此不能在 static 成员函数中使用（后续会讲到 static 成员）。

int main()
{
	Student *pstu = new Student;
	pstu -> setname("李华");
	pstu -> setage(16);
	pstu -> setscore(96.5);
	pstu -> show();
	pstu ->printThis();
	
	Student *pstu1 = new Student;
	pstu1 -> printThis();
	cout << pstu1 << endl;
	
	Student *pstu2 = new Student;
	pstu2 -> printThis();
	cout << pstu2 << endl;
	return 0;
}
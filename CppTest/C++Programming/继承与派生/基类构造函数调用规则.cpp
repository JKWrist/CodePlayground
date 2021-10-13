#include <iostream>
using namespace std;
//基类People
class People
{
public:
	People();  //基类默认构造函数
	People(char *name, int age);
protected:
	char *m_name;
	int m_age;
};
People::People(): m_name("xxx"), m_age(0){ }
People::People(char *name, int age): m_name(name), m_age(age){}


//派生类Student
class Student: public People
{
public:
	Student();
	Student(char*, int, float);
public:
	void display();
private:
	float m_score;
};
Student::Student(): m_score(0.0){ }  //派生类默认构造函数
Student::Student(char *name, int age, float score)
: People(name, age), m_score(score){ }
void Student::display(){
	cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<"。"<<endl;
}

int main()
{
	Student stu1;
	stu1.display();
	Student stu2("小明", 16, 90.5);
	stu2.display();
	return 0;
}
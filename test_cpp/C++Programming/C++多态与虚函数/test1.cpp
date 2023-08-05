#include <iostream>
using namespace std;
//基类People
class People{
public:
	People(char *name, int age);
	void display();
protected:
	char *m_name;
	int m_age;
};
People::People(char *name, int age): m_name(name), m_age(age){}
void People::display(){
	cout<<m_name<<"今年"<<m_age<<"岁了，是个无业游民。"<<endl;
}
//派生类Teacher
class Teacher: public People{
public:
	Teacher(char *name, int age, int salary);
	void display();
private:
	int m_salary;
};
Teacher::Teacher(char *name, int age, int salary): People(name, age), m_salary(salary){}
void Teacher::display(){
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
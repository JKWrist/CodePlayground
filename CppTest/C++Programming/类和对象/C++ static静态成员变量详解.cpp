//对象的内存中包含了成员变量，不同的对象占用不同的内存（已在《C++对象的内存模型》中提到），这使得不同对象的成员变量相互独立，它们的值不受其他对象的影响。例如有两个相同类型的对象 a、b，它们都有一个成员变量 m_name，那么修改 a.m_name 的值不会影响 b.m_name 的值。

//使用静态成员变量来实现多个对象共享数据的目标
#include <iostream>
using namespace std;
class Student
{
public:
	Student(char *name, int age, float score);
	void show();
private:
	static int m_total;  //静态成员变量
private:
	char *m_name;
	int m_age;
	float m_score;
};
//初始化静态成员变量
int Student::m_total = 0;
Student::Student(char *name, int age, float score): m_name(name), m_age(age), m_score(score)
{
	m_total++;  //操作静态成员变量
}
void Student::show()
{
	cout<<m_name<<"的年龄是"<<m_age<<"，成绩是"<<m_score<<"（当前共有"<<m_total<<"名学生）"<<endl;
}

int main()
{
	//创建匿名对象
	(new Student("小明", 15, 90)) -> show();
	(new Student("李磊", 16, 80)) -> show();
	(new Student("张华", 16, 99)) -> show();
	(new Student("王康", 14, 60)) -> show();
	return 0;
}
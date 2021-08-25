#include<iostream>
using namespace std;
//基类People
class People{
public:
	void setname(char *name);
	void setage(int age);
	void sethobby(char *hobby);
	char *gethobby();
protected:
	char *m_name;
	int m_age;
private:
	char *m_hobby;
};
void People::setname(char *name){ m_name = name; }
void People::setage(int age){ m_age = age; }
void People::sethobby(char *hobby){ m_hobby = hobby; }
char *People::gethobby(){ return m_hobby; }


//派生类Student
class Student: public People{
public:
	void setscore(float score);
protected:
	float m_score;
};
void Student::setscore(float score){ m_score = score; }


//派生类Pupil
class Pupil: public Student{
public:
	void setranking(int ranking);
	void display();
private:
	int m_ranking;
};
void Pupil::setranking(int ranking){ m_ranking = ranking; }
void Pupil::display()
{
	cout<<m_name<<endl<<
	"的年龄是"<<m_age<<endl<<
	"考试成绩为"<<m_score<<endl<<
	"班级排名第"<<m_ranking<<endl<<
	"TA喜欢"<<gethobby()<<"。"<<endl;
}

int main()
{
	
	//Student 继承自 People，Pupil 又继承自 Student，它们的继承关系为 People --> Student --> Pupil。Pupil 是最终的派生类，它拥有基类的 m_name、m_age、m_score、m_hobby 成员变量以及 setname()、setage()、sethobby()、gethobby()、setscore() 成员函数。
	Pupil pup;
	pup.setname("小明");
	pup.setage(15);
	pup.setscore(92.5f);
	pup.setranking(4);
	pup.sethobby("乒乓球");
	pup.display();
	return 0;
}
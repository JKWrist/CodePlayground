#include <iostream>
using namespace std;

//基类
class People
{
public:
	virtual void func(){ }
};

//派生类
class Student: public People{ };
int main()
{
	People *p;
	int n;

	cin>>n;
	if(n <= 100)
	{
		p = new People();
	}
	else
	{
		p = new Student();
	}
	
	//根据不同的类型进行不同的操作
	if(typeid(*p) == typeid(People))
	{
		cout<<"I am human."<<endl;
	}
	else
	{
		cout<<"I am a student."<<endl;
	}
	return 0;
}
//空指针访问成员函数

#include <iostream>
using namespace std;

class Person
{
public:
	void showClass()
	{
		cout << "class Name is Person" << endl;
	}

	void showAge()
	{
		if(this == NULL)
		{
			return;
		}
		cout << "age = " << this->m_Age << endl;
	}

	int m_Age;
};

void test01()
{
	Person * p = NULL;
	//p->showAge();
	p->showClass();   //说明了成员函数没有存储在对象数据中
}

int main()
{
	test01();
	return 0;
}
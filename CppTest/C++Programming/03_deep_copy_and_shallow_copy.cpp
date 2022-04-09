//深浅拷贝问题

#include <iostream>
using namespace std;

class Person
{
public:
	Person(char * name, int age)
	{
		m_Name = (char *)malloc(strlen(name) + 1);
		cout << "姓名长度" << strlen(name) << endl;
		memset(m_Name, 0, strlen(m_Name) + 1);
		strcpy(m_Name, name);
		m_Age = age;
	}

	// Person(const Person &p)
	// {
	// 	m_Name = (char *)malloc(strlen(p.m_Name) + 1);
	// 	memset(m_Name, 0, strlen(p.m_Name) + 1);
	// 	strcpy(m_Name, p.m_Name);
	// 	m_Age = p.m_Age;
	// }

	~Person()
	{
		if(m_Name != NULL)
		{
			cout << "Person析构调用" << endl;
			free(m_Name);
			m_Name = NULL;
		}
	}

	char * m_Name;  //姓名
	int m_Age;		//年龄
};

void test01()
{
	Person p1("德玛西亚", 18);
	cout << "姓名 " << p1.m_Name << " 年龄 " << p1.m_Age << endl;

	Person p2(p1);
	cout << "姓名 " << p2.m_Name << " 年龄 " << p2.m_Age << endl;
}

int main()
{
	test01();

	return 0;
}
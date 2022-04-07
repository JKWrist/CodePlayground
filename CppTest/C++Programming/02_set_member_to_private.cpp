//将成员设置为私有

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}
	//获取姓名
	string getName()
	{
		return m_Name;
	}

	//获取年龄
	int getAge()
	{
		return m_Age;
	}

	//设置年龄
	void setAge(int age)
	{
		if ( age < 0 || age > 150)
		{
			cout << "你这个老妖精" << endl;
			return;
		}
		m_Age = age;
	}

	//设置情人
	void setLover(string lover)
	{
		m_Lover = lover;
	}

private:
	//设置姓名
	string m_Name; //姓名 可读可写
	string m_Lover; //情人
	int m_Age;
};

void test01()
{
	Person p;
	//可以将char * 隐式类型转换为 string
	p.setName("张三");
	cout << "姓名： " << p.getName() << endl;

	//获取年龄
	p.setAge(100);
	cout << "年龄： " << p.getAge() << endl;

	//设置情人
	p.setLover("小白");

	//cout << "张三情人是："<< p.m_Lover <<endl; //情人是只写权限  外部访问不到
}

//将成员属性设置为私有的好处，自己可以控制读写权限
//可以对设置内容 增加有效性的验证
int main()
{
	test01();

	return 0;
}
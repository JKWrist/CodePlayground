#include <iostream>
#include <string>
using namespace std;

//设计一个类，求圆的周长
const double PI = 3.14;
//class + 类名
//周长公式： 2*PI*r

class Circle
{
public: //公共权限
	//类中的函数 称为 成员函数/成员方法
	double calculateZC()
	{
		return 2 * PI * m_R;
	}

	//设置半径
	void setR(int r)
	{
		m_R = r;
	}

	//获取半径
	int getR()
	{
		return m_R;
	}

	//类中的变量 称为 成员变量/成员属性
	//半径
	int m_R;
};

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-06 19:56:51
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	Circle c1; //通过类 创建一个对象 实例化对象
	//给从c1 半径赋值
	c1.setR(10);
	
	//求c1圆周长
	cout << c1.calculateZC() << endl;
}



//设计一个学生类，属性有姓名和学号，可以给姓名和学号赋值，可以显示学生的姓名和学号
class Student
{
public:
	//设置姓名
	void setName(string name)
	{
		m_Name = name;
	}

	//设置学号
	void setID(int ID)
	{
		m_ID = ID;
	}

	//显示学生信息
	void showStudent()
	{
		cout << "姓名 " << m_Name << " 学号 " << m_ID << endl;
	}

	//姓名
	string m_Name;
	//学号
	int m_ID;
};

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-06 19:56:54
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test02()
{
	Student s1;
	s1.m_Name = "张三";
	s1.m_ID = 1;

	cout << "姓名 " << s1.m_Name << " 学号 " << s1.m_ID << endl;

	Student s2;
	s2.setName("李四");
	s2.setID(2);
	s2.showStudent();

	Student s3;
	s3.setName("王五");
	s3.setID(3);
	s3.showStudent();
}

int main()
{
	test01();
	test02();
	return 0;
}

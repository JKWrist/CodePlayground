//成员函数作为友元函数
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Building;  //先声明一下
class GoodGay
{
public:
	GoodGay();
	void visit1();
	void visit2();
	Building *m_building;
};

class Building
{
	//让GoodGay成为Building类的好朋友，可以访问私有成员
	friend void GoodGay::visit1();
public:
	Building();
	string m_SittingRoom;
private:
	string m_BedRoom;
};


Building::Building()
{
	m_SittingRoom = "客厅";
	m_BedRoom = "卧室";
}

GoodGay::GoodGay()
{
	m_building = new Building;
}

void GoodGay::visit1()
{
	cout << "好基友访问" << m_building->m_SittingRoom << endl;
	cout << "好基友访问" << m_building->m_BedRoom << endl;
}

void GoodGay::visit2()
{
	cout << "好基友访问" << m_building->m_SittingRoom << endl;
	//cout << "好基友访问" << m_building->m_BedRoom << endl;
}

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-12 21:48:32
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	GoodGay gay;
	gay.visit1();
	gay.visit2();
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-12 21:48:32
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	test01();
	return 0;
}

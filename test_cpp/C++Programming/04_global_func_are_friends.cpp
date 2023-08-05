//全局函数做友元函数

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

class Building
{
	friend void goodGay(Building * building);
	//利用friend 关键字让全局函数 goodGay作为本类好朋友，可以访问私有成员变量
public:
	Building()
	{
		this->m_SittingRoom = "客厅";
		this->m_BedRomm = "卧室";
	}
public:
	string m_SittingRoom; //客厅
private:
	string m_BedRomm;	//卧室
};

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-12 21:38:52
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void goodGay(Building * building)
{
	cout << "好基友正在访问" << building->m_SittingRoom << endl;
	cout << "好基友正在访问" << building->m_BedRomm << endl;
	//'m_BedRomm' is a private member of 'Building'
}

/****************************************************************
 *  函数名称：
 *  创建日期：2022-04-12 21:45:00
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
void test01()
{
	Building building;
	goodGay(&building);
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-04-12 21:38:52
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

#include  "Person.hpp"

void test01()
{
	Person <string, int> p("xiaobai", 9);
	p.showPerson();
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-05-08 15:13:58
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
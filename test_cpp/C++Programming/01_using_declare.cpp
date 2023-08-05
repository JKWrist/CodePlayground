//using 声明以及 using 编译指令
#include <iostream>

using namespace std;

namespace KingGlory
{
	int id = 1;
}

namespace LOL
{
	int id = 2;
}

void test01()
{
	cout << "-------------------" << endl;
	int id = 3;

	//1、using声明
	//using KingGlory::id;  // conflicting declaration

	//当using声明  与  就近原则  同时出现时出错，应该避免
	cout << id << endl;
}

void test02()
{
	cout << "-------------------" << endl;
	int id = 2;

	//2、using 编译指令 
	using namespace KingGlory;
	using namespace LOL;
	//当 using编译指令 与 就近原则同时出现时，优先就近原则
	//当 using编译指令有多个，需要加作用域 区分
	cout << id << endl;
	cout << KingGlory::id << endl;
	cout << LOL::id << endl;
}

int main()
{
	test01();

	test02();

	return 0;
}

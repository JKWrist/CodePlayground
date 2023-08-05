
//双冒号作用域运算符

#include <iostream>

int atk = 1000;

void test01()
{
	int atk = 2000;
	std::cout << "atk = " << atk << std::endl;
	
	//::代表作用域 如果前面什么都不添加 代表全局作用域
	std::cout << "全局 atk = " << ::atk << std::endl;
}

int main()
{
	test01();
	return 0;
}


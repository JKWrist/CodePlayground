//常量的引用
#include <iostream>

using namespace std;

void test01()
{
	//int &ref = 10;

	const int &ret  = 10;  //加了const之后，相当于写成 int temp = 10; const int &ref = tmp;
	int *p = (int *)&ret;
	*p = 1000;

	cout << ret << endl;
}

void showValue(const int &a)
{
	//a = 10000;
	cout << "a = " << a << endl;
}

//常量引用的使用场景，修饰函数中的形参，防止误操作
void test02()
{
	int a = 100;
	showValue(a);
}

int main()
{
	test01();
	test02();
	return 0;
}
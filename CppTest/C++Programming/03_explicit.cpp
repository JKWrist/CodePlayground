//explicit的使用
#include <iostream>

using namespace std;

class MyString
{
public:
	MyString(char * str)
	{
		cout << 1 << endl;
	}

	//explicit用途，防止利用隐式类型转换方式来构造对象
	explicit MyString(int len)
	{
		cout << 2 << endl;
	}

	// MyString(int len)
	// {
	// 	cout << 2 << endl;
	// }
};

void test01()
{
	MyString str1(10);

	MyString str2 = MyString(100);

	MyString str3 = 10;
}

int main()
{
	test01();

	return 0;
}

#include<iostream>
#include "myString.h"

using namespace std;

void test01()
{
	MyString str = "abc";

	cout << str << endl;

	cout << "请重新给str赋值: " << endl;

	cin >> str;

	cout << "str 新的值为: " << str << endl;


	MyString str2 = str;

	cout << "str2 = " << str2 << endl;

}

void test02()
{
	MyString str = "abcd";

	MyString str2 = "aaa";

	str2 = str;

	cout << "str2 = " << str2 << endl;

	cout << "str2[0] = " << str2[0] << endl;

	str2[0] = 'z';

	cout << "str2[0]改为z后输出: " << str2 << endl;


	// MyString str3 = "abc";
	// MyString str4 = "def";
	// MyString str5 = str3 + str4;
	// MyString str6 = str5 + "ghe";
	// cout << "str5 = " << str5 << endl;
	// cout << "str6 = " << str6 << endl;


	// if (str5 == str6)
	// {
	// 	cout << "str5 == str6" << endl;
	// }
	// else
	// {
	// 	cout << "str5 != str6" << endl;
	// }

	// if ( str6 == "abcdefghe")
	// {
	// 	cout << "str6 = abcdefghe" << endl;
	// }
	// else
	// {
	// 	cout << "str6 != abcdefghe" << endl;
	// }

}


int main()
{
	test01();
	test02();
	int a = 10;
	cin >> a;
	cout << "a  = " << a << endl;
}
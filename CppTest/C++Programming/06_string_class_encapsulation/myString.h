#ifndef __MY_STRING_H__
#define __MY_STRING_H__
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;

class MyString
{
	friend ostream& operator<<(ostream & cout, MyString &str);
	friend ostream& operator>>(ostream & cin,  MyString &str);
public:
	//有参构造函数
	MyString(char * str);
	//拷贝构造函数
	MyString(const MyString & str);

	//重载=运算符
	MyString & operator=(const char * str);
	MyString & operator=(const MyString & str);

	//重载[]运算符
	char & operator[](int index);

	//重载+运算符
	MyString & operator+(const char * str);
	MyString & operator+(const MyString & str);

	//重载==运算符
	bool operator==(const char * str);
	bool operator==(const MyString &str);

	~MyString();
private:
	char *m_String; //维护在堆区开辟的字符数组
	int m_Size;
};

#endif
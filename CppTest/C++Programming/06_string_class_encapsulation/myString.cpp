#include "myString.h"

ostream& operator<<(ostream & cout, MyString &str)
{
	cout << str.m_String;
	return cout;
}

ostream& operator>>(ostream & cin,  MyString &str)
{
	//先清空原来的堆区
	if(str.m_String)
	{
		delete [] str.m_String;
		str.m_String = NULL;
	}
	char buf[1024] = {0};
	cin >> buf;
	
	str.m_String = new char [strlen(buf) + 1];
	strcpy(str.m_String, buf);
	str.m_Size = strlen(buf);
	
	return cin;
}

//有参构造函数
MyString::MyString(char * str)
{
	m_String = new char[strlen(str) + 1];
	strcpy(m_String, str);
	m_Size = strlen(str);
}

//拷贝构造函数
MyString::MyString(const MyString & str)
{
	m_String = new char [strlen(str.m_String)];
	strcpy(m_String, str.m_String);
	m_Size = strlen(str.m_String);
}

//重载=运算符
MyString & MyString::operator=(const char * str)
{
	if(m_String)
	{
		delete [] m_String;
		m_Size = 0;
		m_String = NULL;
	}
	m_String = new char[strlen(str) + 1];
	strcpy(m_String, str);
	m_Size = strlen(str);

	return *this;
}

MyString & MyString::operator=(const MyString & str)
{
	if(m_String)
	{
		delete [] m_String;
		m_Size = 0;
		m_String = NULL;
	}
	m_String = new char[strlen(str.m_String) + 1];
	strcpy(m_String, str.m_String);
	m_Size = strlen(str.m_String);
	return *this;
}

// //重载[]运算符
// char & MyString::operator[](int index)
// {
// 	return m_String[index];
// }

// //重载+运算符
// MyString & MyString::operator+(const char * str)
// {

// }
// MyString & MyString::operator+(const MyString & str)
// {

// }

// //重载==运算符
// bool MyString::operator==(const char * str)
// {

// }

// bool MyString::operator==(const MyString &str)
// {

// }

MyString::~MyString()
{
	if(m_String)
	{
		delete [] m_String;
		m_String = NULL;
	}
}
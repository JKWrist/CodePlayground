#include <iostream>
#include <string.h>
#include <string>

using namespace std;
class String
{
public:
	//五参构造函数
	String()
	: _pstr(NULL)
	{ 
		cout << "String()" << endl;
	}	
	
	//有参构造函数
	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char *)" << endl;
	}
	
	//复制构造函数
	String(const String & rhs)
	{
		if(rhs._pstr != NULL)
		{
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
			cout << "String(const String &)" << endl;
		}
	}
	
	//赋值运算符函数， 赋值号也有返回值类型
	String & operator = (const String & rhs)
	{
//		if(this != rhs) //先判断赋值号左右是不是一个东西
//		{
			delete [] _pstr;	
			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
			cout << "String & operator = (const String & rhs)" << endl;
//		}
		return *this;
	}
	
	void print()
	{
		if(_pstr)
			cout << _pstr << endl;
	}
	~String()
	{
		if(_pstr)
			delete []_pstr;
		cout << "~String()" << endl;
	}
private:
	char * _pstr;
};
int main(int argc, char *argv[]) 
{
	
	String s1;
	s1.print();
	
	String s2("hello");
	s2.print();
	
	String s3 = s2;
	s3.print();
	
	String s4 = "test";
	s4.print();
	
//	String s5 = s1;
//	s5.print();
		
	return 0;
}
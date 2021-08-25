#include <iostream>
#include <string>
#include <exception>
using namespace std;
int main()
{
	string str = "http";
	try
	{
		//因为[ ]不会检查下标越界，不会抛出异常，所以即使有错误，try 也检测不到。换句话说，发生异常时必须将异常明确地抛出，try 才能检测到；如果不抛出来，即使有异常 try 也检测不到。所谓抛出异常，就是明确地告诉程序发生了什么错误。
		char ch1 = str[100];
		cout << ch1 << endl;
	}
	catch(exception e)
	{
		cout<<"[1]out of bound!"<<endl;
	}
	
	
	try
	{
		char ch2 = str.at(100);
		cout << ch2 << endl;
	}
	catch(exception &e)
	{  
		//exception类位于<exception>头文件中
		cout<<"[2]out of bound!"<<endl;
	}
	return 0;
}
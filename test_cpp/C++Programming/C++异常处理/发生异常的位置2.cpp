#include <iostream>
#include <string>
#include <exception>
using namespace std;
void func()
{
	throw "Unknown Exception";  //抛出异常
	cout << "[1]This statement will not be executed." << endl;
}
int main()
{
	try
	{
		func();
		cout << "[2]This statement will not be executed." << endl;
	}
	catch(const char* &e)
	{
		cout<<e<<endl;
	}
	return 0;
}
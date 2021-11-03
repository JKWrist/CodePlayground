#include <iostream>
#include <string>
#include <exception>
using namespace std;
int main()
{
	try
	{
		throw "Unknown Exception";  //抛出异常
		cout << "This statement will not be executed." << endl;
	}
	catch(const char* &e)
	{
		cout<<e<<endl;
	}
	return 0;
}
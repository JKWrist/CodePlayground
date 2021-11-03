#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s = "-\r\ndaas-j-\r\nkdj-al-\r\n";
	string::iterator it;
	for (it = s.begin(); it != s.end(); it++)
	{
		if (*it == '-')
		{
			s.erase(it); //STL erase函数
			it--;
		}
		if (*it == '\r')
		{
			s.erase(it); //STL erase函数
			it--;
		}
		if (*it == '\n')
		{
			s.erase(it); //STL erase函数
			it--;
		}
	}
	cout << s << endl;
	return 0;
}
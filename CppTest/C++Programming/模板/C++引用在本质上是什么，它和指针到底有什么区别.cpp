#include <iostream>
using namespace std;
int main()
{
	int a = 99;
	int &r = a;
	
	cout << a << ", "<< r << endl;
	cout << &a << ", "<< &r << endl;
	
	return 0;
}
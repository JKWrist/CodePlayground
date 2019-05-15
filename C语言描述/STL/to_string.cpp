#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) 
{
	string s1 = to_string(123);
	cout << s1 << endl;
	string s2 = to_string(4.5);
	cout  << s2 << endl;
	cout << s1 + s2 << endl;
	printf("%s\n", (s1+s2).c_str());
	return 0;
}
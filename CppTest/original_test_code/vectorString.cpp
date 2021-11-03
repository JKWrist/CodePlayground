#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char *argv[]) 
{
	vector<string> l;
	for(int i = 0; i < 10; i++)
	{
		l.push_back("asa");
	}
	cout << l.size() << endl;
	cout << sizeof(unsigned char) << endl;
}
#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) 
{
	string sz[]= {
		"a",
		"bsd",
		"c",
		"dsdf",
		"e",
		"asdf"};
		
	cout << "sizeof(sz) = " << 	sizeof(sz) << endl;
	
	for(int i = 0 ; i < sizeof(sz)/sizeof(string); i++)
	{
		cout << "i = " << i << "  sz[i]" << sz[i] << endl;
	}
}
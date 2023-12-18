#include <iostream>
#include <string>
using namespace std;
int main(int argc, char *argv[]) 
{
	string str = "hello world";
	str.substr(0, str.length() - 3);
	str.erase(0, 5);	
}
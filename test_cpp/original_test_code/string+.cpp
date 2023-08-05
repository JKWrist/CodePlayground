#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) 
{
	string s1 = "789";
	const char * s2 = "890";
//	const char * s3 = NULL;
//	s1 += s2;
//	s1 += s3;
	s1 += s2;
	cout << s1 <<endl; 
	
	printf("s1 = %s\n", s1.c_str());
	
	string str = "hello";
	str.insert(1, "***");
	cout << str << endl;

	str.erase(1, 3);  //从1号位置开始3个字符
	cout << str << endl;
	
	cout << '\\' << endl;
	cout << (1 % 8) << endl;
	cout << (1 / 8) << endl;
	
	string name("rockderia^jb");
	cout << "firstname = " << name.substr(0,name.find('^')) << endl << "secondname = " << name.substr(name.find('^') + 1) << endl;
}
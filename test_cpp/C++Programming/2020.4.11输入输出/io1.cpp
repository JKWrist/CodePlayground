#include <iostream>
#include <string>
using namespace std;

void printCinStatus()
{
	cout << "cin's badbit = " << cin.bad() << endl;
	cout << "cin's failbit = " << cin.fail() << endl;
	cout << "cin's eofbit = " << cin.eof() << endl;
	cout << "cin's goodbit = " << cin.good() << endl;
}
int main(int argc, char *argv[]) 
{
	cout << "sizeof(cin)" << sizeof(cin) << endl;
	cout << "sizrof(cout)" << sizeof(cout) << endl;
	
	int number;
	printCinStatus();
	
	while(cin >> number)
		cout << "111 number = " << number << endl;;
	
	cout << endl << "重置流的状态" << endl;
	cin.clear();
	cin.ignore(1024, '\n');
	printCinStatus();
		
//	cin >> number;  //当流的状态不是good时，是不能正常工作的
//	cout << endl << "222 number = " << number << endl; 
	string line;;
	cin >> line;
	cout << endl << line << endl;
	printCinStatus();
}
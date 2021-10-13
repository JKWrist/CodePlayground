#include <iostream>

using namespace std;

void test1()
{
	int number;
	cout << "pls input a valid integer:" << endl;
	while(cin >> number, !cin.eof())
	{
		if(cin.bad())
		{
			cout << "stream has corrupted" << endl;
			return;
		}
		else if(cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Pls input a valid integer:" << endl;
			continue;
		}
		cout << "number = " << number << endl;
	}
}
int main(int argc, char *argv[]) 
{
	test1();
}
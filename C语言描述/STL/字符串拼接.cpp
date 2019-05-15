#include <iostream>
#include <cctype>
using namespace std;
int main(int argc, char *argv[]) 
{
	char c;
	cin >> c;
	if (isalpha(c))
		cout << c << " "<< "is alpha" << endl;
	c = 'A';
	c = tolower(c);
		cout << c;
	return 0;
}
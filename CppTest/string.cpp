#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	string foo("quuus");
	
	char bar[8];22
	foo.copy(bar, sizeof(bar));
	cout << bar << endl;
}
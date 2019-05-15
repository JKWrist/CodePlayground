#include <iostream>
#include <bitset>

using namespace std;
int main(int argc, char *argv[]) 
{
	bitset<5>b ("11");
	cout << b << endl;
	for(int i = 0; i < 5; i++)
		cout << b[i];
	cout << endl << b.any() << endl;
	cout << b.none() << endl;
	cout << b.count() << endl;
	cout << b.size() << endl;
	cout << b.test(2) << endl;
	b.set(4);
	for(int i = 0; i < 5; i++)
			cout << b[i];
			cout << endl;
	b.reset();
	for(int i = 0; i < 5; i++)
			cout << b[i];
			cout << endl;
	b.flip();
	for(int i = 0; i < 5; i++)
			cout << b[i];
			cout << endl;
}
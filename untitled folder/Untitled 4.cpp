#include <iostream>
#include <iomanip>
using namespace std;
int main(int argc, char *argv[]) 
{
	int n;
	double db;
	char c;
	char str[10];
	cin >> n >> db >> c >> str;
	printf("%d\n", n);
	cout << n << endl << db << endl << c <<"\n"<< str <<endl;
	cout << setiosflags(ios::fixed) << setprecision(2) << 123.4567 <<endl;
	return 0;
}
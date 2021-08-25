#include <iostream>
#include <set>
using namespace std;
void test0()
{
	int arr[10] = {1,2,3,4,5,6,7,8,9,0};
	set<int> numbers(arr, arr+10);
	
	cout << numbers.size() << endl;
}

int main(int argc, char *argv[]) 
{
	test0();
	return 0;
}
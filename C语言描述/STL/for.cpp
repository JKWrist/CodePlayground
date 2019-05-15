#include <iostream>

using namespace std;
int main(int argc, char *argv[]) 
{
	int arr[4] = {1,2,3,4};
	for (int i : arr)
		cout << i << endl;
}
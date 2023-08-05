#include <iostream>
using namespace std;
int main()
{
	int nums[] = {1, 2, 3};
	try
	{
		throw nums;
		cout<<"This statement will not be executed."<<endl;
	}
	catch(const int *)
	{
		cout<<"Exception type: const int *"<<endl;
	}
	return 0;
}
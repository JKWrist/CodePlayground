#include <iostream>
#include <vector> 
using namespace std;

void test0()
{
	vector<int> numbers(10);
	
	vector<int>::iterator it;
	
	for(it = numbers.begin(); it != numbers.end(); it++)
	{
		cout << *it << " ";
	} 
	cout << endl;
}
int main(int argc, char *argv[]) 
{
	test0();
}
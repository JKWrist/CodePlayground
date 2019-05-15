#include <iostream>
#include <stack>
using namespace std;
int main(int argc, char *argv[]) 
{
	stack<int> s;
	for (int i = 0; i < 6; i++)
		s.push(i);
	cout << s.top() << endl;
	cout << s.size() << endl;
	s.pop();	
	cout << s.size() << endl;
}
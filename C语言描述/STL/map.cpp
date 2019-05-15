#include <iostream>
#include <map>
#include <string>
using namespace std;
int main(int argc, char *argv[]) 
{
	map<string, int> m;
	m["hello"] = 2;
	cout << m["hello"] << endl;
	cout << m["world"] << endl;
	
	m["world"] = 3;
	m[","] = 1;
	for (auto it = m.begin(); it != m.end(); it++)
		cout << it->first << " " << it->second << endl;
	cout << m.begin()->first << " " << m.begin()->second << endl;
	cout << m.rbegin()->first << " " << m.rbegin()->second << endl;
	return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(int argc, char *argv[]) 
{
	int n;
	int max;
	cin >> n;
	map<int,int> m;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		++m[x];
	}
	
	auto it = m.begin();
	++it;
	max = 0;
	auto pre = m.begin();
	for (; it != m.end(); ++it,++pre)
	{
		if(it->first - pre->first > max)
			max = it->first - pre->first;
	}
	cout << max;
	return 0;
}
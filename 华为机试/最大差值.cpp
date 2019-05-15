#include <iostream>
#include <map>
using namespace std;
int main(int argc, char *argv[]) 
{
	map<int , int>m;
	int n, x;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		++m[x];
	}
	auto it = m.begin();
	it++;
	auto pre = m.begin();
	int max = 0;
	
	for(; it != m.end(); it++, pre++)
	{
		if(it->first - pre->first > max)
			max = it->first - pre->first;
	}	
	printf("%d", max);
	return 0;
}
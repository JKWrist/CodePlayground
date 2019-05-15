#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) 
{
	vector<int> vec;
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		vec.push_back(num);
	}	
	sort(vec.begin(), vec.end());
	auto end_unique = unique(vec.begin(), vec.end());
	vec.erase(end_unique, vec.end());
	
	for(auto it = vec.begin(); it != vec.end(); it++)
		cout << *it << endl;
	return 0;
}
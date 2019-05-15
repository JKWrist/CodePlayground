#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) 
{
	int n;
	cin >> n;
	vector <long long> temp(n);
	long max1 = 1;
	long max2 = 1;
	long max3 = 1;
	long min1 = 1;
	long min2 = 1;
	for (int i = 0; i  < n; i++)
	{
		cin >> temp[i];
		if(temp[i] > max3)
		{
			max1 = max2;
			max2 = max3;
			max3 = temp[i];
		}
		else if(temp[i] > max2)
		{
			max1 = max2;
			max2 = temp[i];
		}
		else if(temp[i] > max1)
		{
			max1 = temp[i];
		}
		else if (temp[i] < min1)
		{
			min2 = min1;
			min1 = temp[i];
		}
		else if (temp[i] < min2)
		{
			min2 = temp[i];
		}
	}	
	
	cout << max(max1 * max2 * max3, max3 * min1 * min2);
}
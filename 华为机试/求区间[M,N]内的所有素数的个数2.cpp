

#include <bits/stdc++.h>
using namespace std;
 
bool isPrime(int n)   //判断一个数是否为素数
{
	if(n<=1)
	{
		return false;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); i++)
		{
			if(n%i == 0)
			{
				return false;
			}
		}
		return true;
	}
}
 
int main()
{
	int M,N;
	cin >> M >> N;
	int cnt = 0;   //记录区间内素数的个数
	for(int i = M; i <= N; i++)
	{
		if(isPrime(i))   
		{
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
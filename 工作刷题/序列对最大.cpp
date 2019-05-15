
#include <iostream>
using namespace std;
int a[100];
int main()
{
	int n,i;
	while(cin>>n)
	{
		a[0]=0;
		for(i=1;i<=n;i++)
		cin>>a[i];
		int ans=a[1];
		int lmax=0;
		for(i=1;i<=n;i++)
		{
			a[i]+=a[i-1];
			if(a[i]-lmax < ans)
			     ans = a[i]-lmax;
			if(a[i] > lmax) lmax=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
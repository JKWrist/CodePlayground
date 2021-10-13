#include <iostream>
using namespace std;
#define SQ(y) y*y

int main()
{
//	int n, sq;
//	cin>>n;
//	sq = SQ(n);
//	cout<<sq<<endl;
	
	int n, sq;
	cin>>n;
	sq = SQ(n+1);
	cout<<sq<<endl; //宏定义是一项“细思极密”的工作，一不小心就会踩坑，而且不一定在编译和运行时发现，给程序埋下隐患。

	return 0;
}
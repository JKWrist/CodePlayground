#include <iostream>
using namespace std;
inline int SQ(int y){ return y*y;}


//在多文件编程时，我建议将内联函数的定义直接放在头文件中，并且禁用内联函数的声明（声明是多此一举）。

int main()
{
	int n, sq;
	cin>>n;
	//SQ(n)
	sq = SQ(n);
	cout<<sq<<endl;
	//SQ(n+1)
	sq = SQ(n+1);
	cout<<sq<<endl;
	//200 / SQ(n+1)
	sq = 200 / SQ(n+1);
	cout<<sq<<endl;
	return 0;
}
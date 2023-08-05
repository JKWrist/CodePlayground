#include <iostream>
using namespace std;
int main()
{
	int a, b;
	bool flag;  //定义布尔变量
	cin >> a >> b;
	flag = a > b;
	cout<<"flag = "<<flag<<endl;
	
	flag = true;
	if(flag)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	
	flag = false;
	if(flag)
	{
		cout<<"true"<<endl;
	}
	else
	{
		cout<<"false"<<endl;
	}
	//true 和 false 是 C++ 中的关键字
	return 0;
}
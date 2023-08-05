#include<iostream>
#include<string.h>//sprintf需要它 
using namespace std; 
int main()
{
	unsigned int i=-1;
	cout<<"int最多能表示多少个数(不包括0)："<<i<<endl;
	
	int x=1;
	while(x>0)
	{
		x++;
	}
	cout << "最小负整数" << x << endl;
	
	
	x--;
	cout << "最大正整数："<< x << endl;
	char buf[100];
	sprintf(buf,"%d",x);
	cout << "最大正整数有多少位："<< strlen(buf);
	return 0;
}
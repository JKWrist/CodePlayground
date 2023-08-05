#include<iostream>

//iostream 是 Input Output Stream 的缩写，意思是“输入输出流”。

//cout 和 cin 都是 C++ 的内置对象，而不是关键字

//cout 和 cin 就分别是 ostream 和 istream 类的对象

using namespace std;
int main(){
	int x;
	float y;
	cout<<"Please input an int number:"<<endl;
	cin>>x;
	cout<<"The int number is x= "<<x<<endl;
	cout<<"Please input a float number:"<<endl;
	cin>>y;
	cout<<"The float number is y= "<<y<<endl;   
	return 0;
}
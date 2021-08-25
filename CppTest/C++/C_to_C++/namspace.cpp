#include <cstdio>
#include <iostream>
#include <string>

//iostream.h：用于控制台输入输出头文件。
//fstream.h：用于文件操作的头文件。
//complex.h：用于复数计算的头文件。


//后来 C++ 引入了命名空间的概念，计划重新编写库，将类、函数、宏等都统一纳入一个命名空间，
//这个命名空间的名字就是std。std 是 standard 的缩写，意思是“标准命名空间”。
void func(){
	//必须重新声明
	using namespace std;
	cout<<"http://c.biancheng.net"<<endl;
}

int main()
{
	func();
	//std::printf("http://c.biancheng.net\n");
	printf("http://c.biancheng.net\n");
	
	//声明命名空间std
	using namespace std;
	//定义字符串变量
	string str;
	//定义 int 变量
	int age;
	//从控制台获取用户输入
	cin>>str>>age;
	//将数据输出到控制台
	cout<<str<<"已经成立"<<age<<"年了！"<<endl;
	return 0;
}
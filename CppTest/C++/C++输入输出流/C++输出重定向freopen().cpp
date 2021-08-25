//cout 和 cerr、clog 的一个区别是，cout 允许被重定向，而 cerr 和 clog 都不支持。值得一提的是，cin 也允许被重定向。

//那么，什么是重定向呢？在默认情况下，cin 只能接收从键盘输入的数据，cout 也只能将数据输出到屏幕上。但通过重定向，cin 可以将指定文件作为输入源，即接收文件中早已准备好的数据，同样 cout 可以将原本要输出到屏幕上的数据转而写到指定文件中。

#include <iostream>    //cin、cout
#include <string>      //string
#include <stdio.h>     //freopen
using namespace std;
int main()  
{
	string name1, name2;
	//将标准输入流重定向到 test.txt 文件
	freopen("test.txt", "r", stdin);
	cin >> name1 >> name2;
	//将标准输出重定向到 out.txt文件
	freopen("out.txt", "w", stdout); 
	cout << name1 << "\n" << name2;
	return 0;
}
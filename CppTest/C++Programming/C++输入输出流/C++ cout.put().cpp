#include <iostream>
#include <string>
using namespace std;
int main()
{
	//输出单个字符 a。
	cout.put('a');
	cout.put('\n');
	
	//put() 函数的参数可以是字符或字符的 ASCII 代码（也可以是一个整型表达式）
	cout.put(65 + 32);
	cout.put('\n');
	cout.put(97);
	cout.put('\n');
	
//	put() 方法专用于向输出流缓冲区中添加单个字符，其语法格式如下：
//	ostream＆put(char c);
//
//	其中，参数 c 为要输出的字符。
//
//	可以看到，该函数会返回一个 ostream 类的引用对象，可以理解返回的是 cout 的引用。这意味着，我们可以像下面这样使用 put() 函数：
//	cout.put(c1).put(c2).put(c3);
	cout.put(71).put(79).put(79). put(68).put('\n');
	
	string str = "ten.c//:ptth";
	cout << str.length() << endl;
	
	
	for (int i = str.length() - 1; i >= 0; i--) 
	{
//		C++ cout 输出流对象常用成员方法
//		put()	输出单个字符。
		cout.put(str[i]);  //从最后一个字符开始输出
	}
	cout.put('\n');
	return 0;
}
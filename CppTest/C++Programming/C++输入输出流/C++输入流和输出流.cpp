#include <iostream>
#include <string>

//C++ cin 输入流对象常用成员方法
//getline(str,n,ch)	从输入流中接收 n-1 个字符给 str 变量，当遇到指定 ch 字符时会停止读取，默认情况下 ch 为 '\0'。
//get()	从输入流中读取一个字符，同时该字符会从输入流中消失。
//gcount() 	返回上次从输入流提取出的字符个数，该函数常和 get()、getline()、ignore()、peek()、read()、readsome()、putback() 和 unget() 联用。
//peek()	返回输入流中的第一个字符，但并不是提取该字符。
//putback(c) 	将字符 c 置入输入流（缓冲区）。
//ignore(n,ch)	从输入流中逐个提取字符，但提取出的字符被忽略，不被使用，直至提取出 n 个字符，或者当前读取的字符为 ch。
//operator >>	重载 >> 运算符，用于读取指定类型的数据，并返回输入流对象本身。

//C++ cout 输出流对象常用成员方法	
//put()	输出单个字符。
//write()	输出指定的字符串。
//tellp()	用于获取当前输出流指针的位置。
//seekp()	设置输出流指针的位置。
//flush()	刷新输出流缓冲区。
//operator <<	重载 << 运算符，使其用于输出其后指定类型的数据。

int main() 
{
	//此程序中并没有考虑 cerr 和 clog 各自特有的含义
	std::string url;
	std::cin >> url;
	std::cout << "cout：" << url << std::endl;
	std::cerr << "cerr：" << url << std::endl;
	std::clog << "clog：" << url << std::endl;
	return 0;
}
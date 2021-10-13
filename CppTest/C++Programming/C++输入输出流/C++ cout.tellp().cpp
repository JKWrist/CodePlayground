#include <iostream> //cin 和 cout
#include <fstream> //文件输入输出流

//通过前面章节的学习我们知道，无论是使用 cout 输出普通数据，用 cout.put() 输出指定字符，还是用 cout.write() 输出指定字符串，数据都会先放到输出流缓冲区，待缓冲区刷新，数据才会输出到指定位置（屏幕或者文件中）。

//值得一提的是，当数据暂存于输出流缓冲区中时，我们仍可以对其进行修改。ostream 类中提供有 tellp() 和 seekp() 成员方法，借助它们就可以修改位于输出流缓冲区中的数据。


//tellp() 成员方法用于获取当前输出流缓冲区中最后一个字符所在的位置

int main() 
{
//	istream：常用于接收从键盘输入的数据；
//	ostream：常用于将数据输出到屏幕上；
//	ifstream：用于读取文件中的数据；
//	ofstream：用于向文件中写入数据；
//	iostream：继承自 istream 和 ostream 类，因为该类的功能兼两者于一身，既能用于输入，也能用于输出；
//	fstream：兼 ifstream 和 ofstream 类功能于一身，既能读取文件中的数据，又能向文件中写入数据。
	
	//定义一个文件输出流对象
	std::ofstream outfile;
	//打开 test.txt，等待接收数据
	outfile.open("test.txt");
	const char * str = "通过前面章节的学习我们知道，无论是使用 cout 输出普通数据，用 cout.put() 输出指定字符，还是用 cout.write() 输出指定字符串，数据都会先放到输出流缓冲区，待缓冲区刷新，数据才会输出到指定位置(屏幕或者文件中)。值得一提的是，当数据暂存于输出流缓冲区中时，我们仍可以对其进行修改。ostream 类中提供有 tellp() 和 seekp() 成员方法，借助它们就可以修改位于输出流缓冲区中的数据。";
	//将 str 字符串中的字符逐个输出到 test.txt 文件中
	//每个字符都会暂时存在输出流缓冲区中
	
	for (int i = 0; i < strlen(str); i++) 
	{
		outfile.put(str[i]);
		//获取当前输出流
		long pos = outfile.tellp();
		std::cout << pos << str[i] << std::endl;
	}
	
	//关闭文件之前，刷新 outfile 输出流缓冲区，使所有字符由缓冲区流入test.txt文件
	outfile.close();
	return 0;
}
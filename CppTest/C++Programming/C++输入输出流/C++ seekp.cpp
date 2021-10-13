#include <iostream> //cin 和 cout
#include <fstream> //文件输入输出流
using namespace std;
int main() 
{
	//定义一个文件输出流对象
	ofstream outfile;
	//打开 test.txt，等待接收数据
	outfile.open("test.txt");
	const char * str = "http://c.cplus/";
	//将 str 字符串中的字符逐个输出到 test.txt 文件中，每个字符都会暂时存在输出流缓冲区中
	for (int i = 0; i < strlen(str); i++) 
	{
		outfile.put(str[i]);
		printf("%d\n", i);
		//获取当前输出流
	}
	cout << "当前位置为：" << outfile.tellp() << endl;
	//调整新进入缓冲区字符的存储位置
	
//	seekp() 方法有如下 2 种语法格式：
//	//指定下一个字符存储的位置
//	ostream& seekp (streampos pos);
//	//通过偏移量间接指定下一个字符的存储位置   
//	ostream& seekp (streamoff off, ios_base::seekdir way);
//	其中，各个参数的含义如下：
//	pos：用于接收一个正整数；、
//	off：用于指定相对于 way 位置的偏移量，其本质也是接收一个整数，可以是正数（代表正偏移）或者负数（代表负偏移）；
//	way：用于指定偏移位置，即从哪里计算偏移量，它可以接收表 1 所示的 3 个值。
	
	outfile.seekp(9);  
	//等价于：
	//outfile.seekp(9, ios::beg);
	//outfile.seekp(-6, ios::cur);
	//outfile.seekp(-6, ios::end);

	cout << "新插入位置为:" << outfile.tellp() << endl;
	const char* newstr = "python/";
	outfile.write("python/", 7);
	//关闭文件之前，刷新 outfile 输出流缓冲区，使所有字符由缓冲区流入test.txt文件
	outfile.close();
	return 0;
}
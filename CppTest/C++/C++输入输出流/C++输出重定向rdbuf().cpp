#include <iostream>
#include <fstream>
using namespace std;

//rdbuf() 函数的语法格式有 2 种，分别为：
//streambuf * rdbuf() const;
//streambuf * rdbuf(streambuf * sb);
//streambuf 是 C++ 标准库中用于表示缓冲区的类，该类的指针对象用于代指某个具体的流缓冲区。
//
//其中，第一种语法格式仅是返回一个指向当前流缓冲区的指针；第二种语法格式用于将 sb 指向的缓冲区设置为当前流的新缓冲区，并返回一个指向旧缓冲区的对象。

int main()
{
	//打开 test.txt 文件，等待读取
	ifstream fin("test.txt");
	//打开 out.txt 文件，等待写入
	ofstream fout("out.txt");
	streambuf *oldcin;
	streambuf *oldcout;
	char a[100];
	//用 rdbuf() 重新定向，返回旧输入流缓冲区指针
	oldcin = cin.rdbuf(fin.rdbuf());
	//从input.txt文件读入
	cin >> a;
	//用 rdbuf() 重新定向，返回旧输出流缓冲区指针
	oldcout = cout.rdbuf(fout.rdbuf());
	//写入 out.txt
	cout << a << endl;
	
	
	//还原标准输入输出流
	cin.rdbuf(oldcin); // 恢复键盘输入
	cout.rdbuf(oldcout); //恢复屏幕输出
	
	//打开的文件，最终需要手动关闭
	fin.close();
	fout.close();
	return 0;
}
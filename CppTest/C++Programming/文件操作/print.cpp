#include <iostream>
#include <fstream>
using namespace std;
int main() 
{
	const char *url ="https://www.hahack.com/codes/cmake/";
	//创建一个 fstream 类对象
	fstream fs;
	//将 test.txt 文件和 fs 文件流关联
	fs.open("test.txt", ios::out);
	//向test.txt文件中写入 url 字符串
	fs.write(url, 10);
	fs.close();
	return 0;
}
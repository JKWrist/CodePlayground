#include <iostream>     //std::cout
#include <fstream>      //std::ofstream
using namespace std;
int main()
{
	const char * url = "https://www.acwing.com/activity/";
	//以文本模式打开out.txt
	ofstream destFile("out.txt", ios::out);
	if (!destFile) 
	{
		cout << "文件打开失败" << endl;
		return 0;
	}
	//向out.txt文件中写入 url 字符串
	destFile << url;
	
	//刷新输出流缓冲区
	//destFile.flush();
		
	//程序抛出一个异常
	throw "Exception";
	
	//关闭打开的 out.txt 文件
	destFile.close();
	return 0;
}
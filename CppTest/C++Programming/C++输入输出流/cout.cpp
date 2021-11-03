#include <iostream>
using namespace std;
int main() 
{
	char url[30] = {0};
	//读取一行字符串
	cin.getline(url, 30);     //回车也一并读取了
	//输出上一条语句读取字符的个数
	cout << "读取了 "<<cin.gcount()<<" 个字符" << endl;
	
	//输出 url 数组存储的字符串
	cout.write(url, 30);
	cout << " strlen(url) = " << strlen(url) << endl;
	return 0;
}
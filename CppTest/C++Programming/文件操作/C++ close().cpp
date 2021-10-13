#include <fstream>
using namespace std;
int main()
{
	const char *url="https://www.acwing.com/activity/";
	ofstream outFile("url.txt", ios::out);
	//向 url.txt 文件中写入字符串
	outFile.write(url, 30);
	//关闭已打开的文件
	outFile.close();
	return 0;
}
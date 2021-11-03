#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	const char *url="https://www.acwing.com/activity/";
	ofstream outFile;
	outFile.close();
	
	if (outFile.fail()) 
	{
		cout << "文件操作过程发生了错误！";
	}
	return 0;
}
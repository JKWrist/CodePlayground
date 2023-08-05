#include <iostream>
using namespace std;
const int MAX_LINE_LEN = 10000;  //假设文件中一行最长 10000 个字符

int main()
{
	char szBuf[MAX_LINE_LEN + 10];
	freopen("test.txt", "r", stdin);  //将标准输入重定向为 test.txt
	while (cin.getline(szBuf, MAX_LINE_LEN + 5))
		cout << szBuf << endl;
	return 0;
}
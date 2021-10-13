#include <iostream>
using namespace std;

int main()
{
	char szBuf[20];
	int n = 120;
	if(!cin.getline(szBuf,6))  //如果输入流中一行字符超过5个，就会出错
		cout << "error" << endl;
	cout << szBuf << endl;
	cin >> n;
	cout << n  << endl;
	cin.clear(); //clear能够清除cin内部的错误标记，使之恢复正常
	cin >> n;
	cout << n << endl;
	return 0;
}
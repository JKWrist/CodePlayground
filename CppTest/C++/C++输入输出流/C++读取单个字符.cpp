#include <iostream>
using namespace std;
int main()
{
//	int c;
//	while ((c = cin.get()) != EOF)
//		cout.put(c);
		
//	ctrl-z 挂起正在运行的进程
//	ctrl-d 发送EOF
//	ctrl-c 结束进程

	int c;
	freopen("test.txt", "r", stdin);  //将标准输入重定向为 test.txt
	while ((c = cin.get()) != EOF)
		cout.put(c);
			
	return 0;
}
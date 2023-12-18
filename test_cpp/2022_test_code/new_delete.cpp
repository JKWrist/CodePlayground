#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	char *pc = new char('a'); //开辟一个内bai存单元，并用括号里的初始du化
	char *pca = new char[15]; //开辟一个数组zhi
	//	PS：
	//	释放内存的方法dao也不一样:
	delete pc;
	delete []pca;
}
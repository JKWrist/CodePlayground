#include <iostream>
using namespace std;

int main() 
{
	const char * str = "http://net";
	cout.write(str, 4);
	
	printf("\n");
	
//	可以看到，该函数会返回一个 ostream 类的引用对象，可以理解返回的是 cout 的引用。这意味着，我们可以像下面这样使用 write() 方法：
//	cout.write(c1, 1).write(c2, 2).write(c3, 3);
//	因为 cout.write(c1, 1) 向输出流缓冲区中添加 c1 字符串中第 1 字符的同时，会返回一个引用形式的 cout 对象
//	所以可以继续用此对象调用 write(c2, 2)，向输出流缓冲区添加 c2 字符串中前 2 个字符，依次类推。
	cout.write("http://", 7).write("net", 7).write("/cplus/", 3);
	
	printf("\n");
	
	cout.write("printfp", 7).write("test", 7);

	return 0;
}
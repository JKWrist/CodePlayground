#include <iostream>

using namespace std;

int main(int argc, char *argv[]) 
{
	//每个输出流都管理一个缓冲区，用来保存程序读写的数据。例如，如果执行下而的代码：
	//文本串可能立即打印出来，但也有可能被操作系统保存在缓冲区中，随后再打印。
	cout << "http://c.cplus/";
	
	cout << "hi!" << endl;  //输出hi和一个换行，然后刷新缓冲区
	cout << "hi!" << flush;  //输出hi，然后刷新缓冲区，不附加任何额外字符
	cout << "hi!" << ends;  //输出hi和一个空字符，然后刷新缓冲区
	
	cout << "11111";
	
	cout << unitbuf;  //所有输出操作后都会立即刷新缓冲区
	//任何输出都立即刷新，无缓冲
	cout << nounitbuf;  //回到正常的缓冲方式
	//警告：如果程序崩溃，输出缓冲区不会被刷新
	
	
	/*关联输入和输出流*/
//	ostream* tie ( ) const;  //返回指向绑定的输出流的指针。
//	ostream* tie ( ostream* os );  //将os指向的输出流绑定的该对象上，并返回上一个绑定的输出流指针。
	
	cin.tie(&cout);  //仅仅是用来展示，标准库已经将 cin 和 cout 关联在一起
	//old_tie 指向当前关联到 cin 的流（如果有的话）
	ostream *old_tie = cin.tie(nullptr);  // cin 不再与其他流关联
	//将 cin 与 cerr 关联，这不是一个好主意，因为 cin 应该关联到 cout
	cin.tie(&cerr);  //读取 cin 会刷新 cerr 而不是 cout
	cin.tie(old_tie);  //重建 cin 和 cout 间的正常关联
	
	return 0;
}
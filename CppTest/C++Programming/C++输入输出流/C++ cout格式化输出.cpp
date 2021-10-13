#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double a = 1.23;
	//设定后续输出的浮点数的精度为 4
	cout.precision(4);
	cout <<"precision: "<< a << endl;
	//设定后续以科学计数法的方式输出浮点数
	cout.setf(ios::scientific);
	cout <<"scientific："<< a << endl << '\n';
	
/////////////////////////////////////////////////////////////////////////////	

	double f = 123;
	//设定后续以科学计数法表示浮点数
	cout.setf(ios::scientific);
	cout << f << '\n';
		
	//删除之前有关浮点表示的设定
	cout.unsetf(ios::floatfield);
	cout << f << '\n';
	
		
	f = 222;
	//设定后续以科学计数法表示浮点数
	cout.setf(ios::adjustfield);
	cout << f << '\n';
	
	f = 333;
	//设定后续以科学计数法表示浮点数
	cout.setf(ios::left | ios::right | ios::internal);
	cout << f << '\n' << '\n';
		
////////////////////////////////////////////////////////////////////////	
	//以十六进制输出整数
	cout << hex << 16 << endl;
	//删除之前设定的进制格式，以默认的 10 进制输出整数
	cout << resetiosflags(ios::basefield)<< 16 << endl;
	double y = 123;
	//以科学计数法的方式输出浮点数
	cout << scientific << y << endl;
	//删除之前设定的科学计数法的方法
	cout << resetiosflags(ios::scientific) << y << endl;
	return 0;
}
#include<iostream>
 
using namespace std;
 
class _iterator
{
	private:
			char *p;
	public:
			_iterator(char*str):p(str){}
			char*&operator++()
			{    
				p+=1;//跟p++同价;
				return p;
			}
};
int main()
{
	char *p="This is C++ program";
	_iterator it(p);
	cout<< "++之前：" << p <<endl;
	char*p1=++it;//把地址向前加了一个char型长度,然后给指针p1
	cout<< "++之后：" << p1 <<endl;
	return 0;
}
#include <iostream>
#include <iomanip>
using namespace std;


//秒表类
class stopwatch
{
public:
	stopwatch()
	: m_min(0)
	, m_sec(0)
	{
		
	}
public:
	void setzero()
	{
		m_min = 0; 
		m_sec = 0; 
	}
	stopwatch run();         	//运行
	stopwatch operator++();  	//++i，前置形式
	stopwatch operator++(int);  //i++，后置形式
	friend ostream & operator << (ostream &, const stopwatch &);
private:
	int m_min;  //分钟
	int m_sec;  //秒钟
};

stopwatch stopwatch::run()
{
	++m_sec;
	if(m_sec == 60)
	{
		m_min++;
		m_sec = 0;
	}
	return *this;
}

//operator++() 函数实现自增的前置形式，直接返回 run() 函数运行结果即可。
stopwatch stopwatch::operator++()
{
	return run();
}

//operator++ (int n) 函数实现自增的后置形式，返回值是对象本身，但是之后再次使用该对象时，对象自增了，所以在该函数的函数体中，先将对象保存，然后调用一次 run() 函数，之后再将先前保存的对象返回。在这个函数中参数n是没有任何意义的，它的存在只是为了区分是前置形式还是后置形式。
stopwatch stopwatch::operator++(int n)
{
	stopwatch s = *this;
	run();
	return s;
}

ostream & operator << (ostream & out, const stopwatch & s)
{
	out << setfill('0') << setw(2) << s.m_min << ":" << setw(2) << s.m_sec;
	return out;
}

int main()
{
	stopwatch s1, s2;
	s1 = ++s2;
	cout << "s1: "<< s1 <<endl;
	cout << "s2: "<< s2 <<endl<<endl;

	s1.setzero();
	s2.setzero();
	
	s1 = s2++;
	cout << "s1: "<< s1 <<endl;
	cout << "s2: "<< s2 <<endl;
	return 0;
}
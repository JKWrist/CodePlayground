#include <iostream>
using namespace std;

//类模板
template<class T1, class T2> class Point
{
public:
	Point(T1 x, T2 y)
	: m_x(x)
	, m_y(y)
	{ 
		
	}
public:
	T1 getX() const
	{ 
		return m_x; 
	}
	void setX(T1 x)
	{ 
		m_x = x; 
	}
	T2 getY() const
	{ 
		return m_y; 
	}
	void setY(T2 y)
	{
		m_y = y; 
	}
	void display() const;
private:
	T1 m_x;
	T2 m_y;
};

template<class T1, class T2>  //这里要带上模板头
void Point<T1, T2>::display() const
{
	cout << "x = "<< m_x << ", y = " << m_y << endl;
}


//类模板的显示具体化（针对字符串类型的显示具体化）
template<> class Point<char*, char*>
{
public:
	Point(char *x, char *y): m_x(x), m_y(y){ }
public:
	char *getX() const{ return m_x; }
	void setX(char *x){ m_x = x; }
	char *getY() const{ return m_y; }
	void setY(char *y){ m_y = y; }
	void display() const;
private:
	char *m_x;  //x坐标
	char *m_y;  //y坐标
};

//这里不能带模板头template<>
//Point 类有两个类型参数 T1、T2，并且都已经被具体化了，所以整个类模板就不再有类型参数了，模板头应该写作template<>。
void Point<char*, char*>::display() const
{
	cout << "x = " << m_x << " | y = " << m_y << endl;
}

int main()
{
	( new Point<int, int>(10, 20) ) -> display();
	( new Point<int, char*>(10, "东京180度") ) -> display();
	( new Point<char*, char*>("东京180度", "北纬210度") ) -> display();
	return 0;
}
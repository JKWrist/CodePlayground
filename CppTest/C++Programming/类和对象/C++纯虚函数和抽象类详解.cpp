#include <iostream>
using namespace std;


//顶层函数不能被声明为纯虚函数
void fun() = 0;   //compile error
class base
{
public :
	//普通成员函数不能被声明为纯虚函数
	void display() = 0;  //compile error
};

//线
class Line
{
public:
	Line(float len);
	virtual float area() = 0;
	virtual float volume() = 0;	//纯虚函数。
protected:
	float m_len;
};
//包含纯虚函数的类称为抽象类（Abstract Class）
//无法实例化，无法创建对象
//原因很明显，纯虚函数没有函数体，不是完整的函数，无法调用，也无法为其分配内存空间。

Line::Line(float len)
: m_len(len)
{ 

}


//矩形
class Rec: public Line
{
public:
	Rec(float len, float width);
	//在 Rec 类中，实现了 area() 函数；所谓实现，就是定义了纯虚函数的函数体。
	//但这时 Rec 仍不能被实例化，因为它没有实现继承来的 volume() 函数，volume() 仍然是纯虚函数，所以 Rec 也仍然是抽象类。
	float area();
protected:
	float m_width;
};

Rec::Rec(float len, float width)
: Line(len), m_width(width)
{ 

}
float Rec::area()
{ 
	return m_len * m_width; 
}


//长方体
class Cuboid: public Rec
{
public:
	Cuboid(float len, float width, float height);
	float area();
	float volume();
protected:
	float m_height;
};

Cuboid::Cuboid(float len, float width, float height)
: Rec(len, width)
, m_height(height)
{ 
	
}

float Cuboid::area()
{ 
	return 2 * ( m_len*m_width + m_len*m_height + m_width*m_height); 
}

float Cuboid::volume()
{ 
	return m_len * m_width * m_height; 
}


//正方体
class Cube: public Cuboid
{
public:
	Cube(float len);
	float area();
	float volume();
};

Cube::Cube(float len)
: Cuboid(len, len, len)
{ 

}

float Cube::area()
{ 
	return 6 * m_len * m_len; 
}

float Cube::volume()
{ 
	return m_len * m_len * m_len; 
}

//抽象基类除了约束派生类的功能，还可以实现多态。请注意第 51 行代码，指针 p 的类型是 Line，但是它却可以访问派生类中的 area() 和 volume() 函数，正是由于在 Line 类中将这两个函数定义为纯虚函数；如果不这样做，51 行后面的代码都是错误的。我想，这或许才是C++提供纯虚函数的主要目的。

int main()
{
	Line *p = new Cuboid(10, 20, 30);
	cout << "The area of Cuboid is " << p->area() << endl;
	cout << "The volume of Cuboid is " << p->volume() << endl;
  
	p = new Cube(15);
	cout << "The area of Cube is " << p->area() << endl;
	cout << "The volume of Cube is " << p->volume() << endl;
	return 0;
}
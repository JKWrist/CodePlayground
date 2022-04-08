#include <iostream>
#include "circle.h"
#include "point.h"

using namespace std;

//利用全局函数 判断点和圆关系
void isInCircle( Circle c , Point p )
{

	int distance = (c.getCenter().getX() - p.getX())*(c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) *(c.getCenter().getY() - p.getY());

	int rDistance = c.getR() * c.getR();

	if (distance == rDistance)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > rDistance)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}

}

void test01()
{
	Point p;
	p.setX(10);
	p.setY(9);

	Circle c1;
	Point p1;
	p1.setX(10);
	p1.setY(0);
	c1.setCenter(p1);
	c1.setR(10);

	c1.isInCircle(p);
}

int main()
{
	test01();

	return 0;
}
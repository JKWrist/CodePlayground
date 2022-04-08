//#program once

#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include <iostream>
#include "point.h"

using namespace std;

//圆类
class Circle
{
public:
	//m_R
	int getR();
	int setR(int tmp);

	//Center
	Point getCenter();
	void setCenter(Point p);
	
	//点与圆的关系
	void isInCircle(Point p);

private:
	int m_R; //半径
	Point m_Center;
};

#endif
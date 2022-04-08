//#program once
#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>
using namespace std;

//点类
class Point
{
public:
	//设置x, y
	void setX(int tmp);
	void setY(int tmp);

	//获取x,y
	int getX();
	int getY();

private:
	int m_X;
	int m_Y;
};

#endif //__POINT_H__

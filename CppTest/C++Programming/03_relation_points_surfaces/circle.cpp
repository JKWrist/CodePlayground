#include "circle.h"

int Circle::getR()
{
	return m_R;
}

int Circle::setR(int tmp)
{
	m_R = tmp;
}

Point Circle::getCenter()
{
	return m_Center;
}

void Circle::setCenter(Point p)
{
	m_Center = p;
}

void Circle::isInCircle(Point p)
{
	int distance_2 = (m_Center.getX() - p.getX())*(m_Center.getX() - p.getX()) + (m_Center.getY() - p.getY())*(m_Center.getY() - p.getY());
	int rdistance_2 = m_R * m_R;

	if(distance_2 == rdistance_2)
	{
		cout << "圆上" << endl;
	}
	else if(distance_2 > rdistance_2)
	{
		cout << "圆外" << endl;
	}
	else if(distance_2 < rdistance_2)
	{
		cout << "圆内" << endl;
	}
}

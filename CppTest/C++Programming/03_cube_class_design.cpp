#include <iostream>
#include <string>

using namespace std;

//设计立方体类，求立方体的面积 (2*a*b + 2*a*c + 2*b*c) 和体积 a*b*c

class Cube
{
public:
	//设置长宽高
	int getL()
	{
		return m_L;
	}
	int getW()
	{
		return m_W;
	}
	int getH()
	{
		return m_H;
	}

	//设置长款高
	int setL(int tmp)
	{
		m_L = tmp;
	}
	int setW(int tmp)
	{
		m_W = tmp;
	}
	int setH(int tmp)
	{
		m_H = tmp;
	}

	//求体积
	int calculateV()
	{
		return (m_L*m_W*m_H);
	}

	//求面积
	int calculateS()
	{
		return (2*m_L*m_W + 2*m_L*m_H + 2*m_W*m_H);
	}

	//判断立方体是否相等
	bool CompareCubebyClass(Cube &c)
	{
		return (m_H == c.getH() && m_L == c.getL() && m_W == c.getH());
	}
private:
	int m_L;
	int m_W;
	int m_H;
};

void test01()
{
	Cube c1;
	c1.setH(10);
	c1.setL(10);
	c1.setW(20);

	cout << "体积 " << c1.calculateV() << endl;
	cout << "面积 " << c1.calculateS() << endl;

	Cube c2;
	c2.setH(20);
	c2.setL(10);
	c2.setW(20);

	cout << "是否相等 " << c1.CompareCubebyClass(c2) << endl;
}

int main()
{
	test01();

	return 0;
}
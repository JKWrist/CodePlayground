//多条案例，电脑组装

#include<iostream>
using namespace std;

//CPU基类
class CPU
{
public:
	virtual void calculate() = 0;
};

//显卡基类
class VideoCard
{
public:
	virtual void display() = 0;
};

//内存基类
class Memory
{
public:
	virtual void storage() = 0;
};

//电脑类
class computer
{
public:

	computer(CPU * cpu, VideoCard * vc, Memory * mem)
	{
		cout << "电脑构造调用" << endl;
		this->m_Cpu = cpu;
		this->m_Vc = vc;
		this->m_Mem = mem;
	}

	void doWork()
	{
		this->m_Cpu->calculate();
		this->m_Vc->display();
		this->m_Mem->storage();
	}

	~computer()
	{
		cout << "电脑析构调用" << endl;
		if (this->m_Cpu)
		{
			delete this->m_Cpu;
			this->m_Cpu = NULL;
		}
		if (this->m_Vc)
		{
			delete this->m_Vc;
			this->m_Vc = NULL;
		}
		if (this->m_Mem)
		{
			delete this->m_Mem;
			this->m_Mem = NULL;
		}
	}
	CPU * m_Cpu;
	VideoCard * m_Vc;
	Memory * m_Mem;
};

//inter厂商
class intelCPU :public CPU
{
public:
	void calculate()
	{
		cout << "intelCPU开始计算了" << endl;
	}
};

class intelVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "intel 显卡开始显示了" << endl;
	}

};

class intelMemory :public Memory
{
public:
	void storage()
	{
		cout << "intel 内存条开始存储了" << endl;
	}
};

//Lenovo 厂商
class LenovoCPU :public CPU
{
public:
	void calculate()
	{
		cout << "Lenovo CPU开始计算了" << endl;
	}
};

class LenovoVideoCard :public VideoCard
{
public:
	void display()
	{
		cout << "Lenovo 显卡开始显示了" << endl;
	}

};

class LenovoMemory :public Memory
{
public:
	void storage()
	{
		cout << "Lenovo 内存条开始存储了" << endl;
	}
};


void test01()
{
	cout << "第一台电脑组成：" << endl;

	CPU * intelCpu = new intelCPU;
	VideoCard * lenovoVC = new LenovoVideoCard;
	Memory * lenovoMem = new LenovoMemory;

	computer c1(intelCpu, lenovoVC, lenovoMem);

	c1.doWork();

	cout << "第二台电脑组成：" << endl;

	CPU * intelCpu2 = new LenovoCPU;
	VideoCard * lenovoVC2 = new intelVideoCard;
	Memory * lenovoMem2 = new intelMemory;

	computer c2(intelCpu2, lenovoVC2, lenovoMem2);

	c2.doWork();
}

int main()
{
	test01();

	return 0;
}
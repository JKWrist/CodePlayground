#include <iostream>
using namespace std;
//军队
class Troops{
public:
	virtual void fight(){ cout<<"Strike back!"<<endl; }
};

//陆军
class Army: public Troops{
public:
	void fight(){ cout<<"--Army is fighting!"<<endl; }
};

//99A主战坦克
class _99A: public Army{
public:
	void fight(){ cout<<"----99A(Tank) is fighting!"<<endl; }
};

//武直10武装直升机
class WZ_10: public Army{
public:
	void fight(){ cout<<"----WZ-10(Helicopter) is fighting!"<<endl; }
};

//长剑10巡航导弹
class CJ_10: public Army{
public:
	void fight(){ cout<<"----CJ-10(Missile) is fighting!"<<endl; }
};



//空军
class AirForce: public Troops{
public:
	void fight(){ cout<<"--AirForce is fighting!"<<endl; }
};

//J-20隐形歼击机
class J_20: public AirForce{
public:
	void fight(){ cout<<"----J-20(Fighter Plane) is fighting!"<<endl; }
};

//CH5无人机
class CH_5: public AirForce{
public:
	void fight(){ cout<<"----CH-5(UAV) is fighting!"<<endl; }
};

//轰6K轰炸机
class H_6K: public AirForce{
public:
	void fight(){ cout<<"----H-6K(Bomber) is fighting!"<<endl; }
};
int main()
{
	//如果不使用多态，那么就需要定义多个指针变量，很容易造成混乱；而有了多态，只需要一个指针变量 p 就可以调用所有派生类的虚函数。
	
	Troops *p = new Troops;
	p ->fight();
	//陆军
	p = new Army;
	p ->fight();
	p = new _99A;
	p -> fight();
	p = new WZ_10;
	p -> fight();
	p = new CJ_10;
	p -> fight();
	//空军
	p = new AirForce;
	p -> fight();
	p = new J_20;
	p -> fight();
	p = new CH_5;
	p -> fight();
	p = new H_6K;
	p -> fight();
	return 0;
}
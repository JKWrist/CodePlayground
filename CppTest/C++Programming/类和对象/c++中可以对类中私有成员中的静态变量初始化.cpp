//问题：我看的书上写的对私有部分的访问可以是公共部分的成员函数，也可以是友员函数，那么可以直接对私有部分的静态成员进行初始化吗？
//回答：
//1.static成员的所有者是类本身和对象，但是多有对象拥有一样的静态成员。从而在定义对象时不能通过构造函数对其进行初始化。
//2.静态成员不能在类定义里边初始化，只能在class body外初始化。
//3.静态成员仍然遵循public，private，protected访问准则。
//4.静态成员函数没有this指针，它不能返回非静态成员，因为除了对象会调用它外，类本身也可以调用。

#include <iostream>
#include <string>

using namespace std;

class Account 
{
public:
	Account(string name, int money):owner(name), amount(money)
	{
		cout << "Account()" << " owner " << owner << " amount " << amount << endl;
	}
	//Account(string name, int money, double rate):owner(name), amount(money), interestRate(rate) { } // 是错误的
	~Account() 
	{
		cout << "~Account()" << endl;
	}
	
	double applyint()
	{	
		cout << "applyint()" << " amount " << amount << " interestRate " << interestRate << endl;
		amount += amount * interestRate;
		return amount;
	}
	//如果将applyint()声明为static double applyint()则错误，因为amount不是//静态成员
	
	static double rate()
	{
		cout << "rate()" << endl;
		return interestRate; // 注意返回值  获取intereRate值
	}
	
	static void rate(double);//设置interestragte返回值
	static double interestRate;//public，其他非成员可以访问
	
private:
	string owner;
	double amount;
	//static double interestRate;  // private, 成员和友元才可访问
	static double initRate();
};

double Account::interestRate = 2.0; //正确的静态成员初始化
//double Account::interestRate = Account::initRate();//用静态成员函数对静态成员进行初始化，正确，因为private成员可以访问private成员，以上两种初始化只能选其一

//Account::interestRate  = 3.0; //错误，不能通过编译，原因不明，按编译结果看，编译器将这个赋值语句当做对静态成员的初始化（因为编译器提醒少了类型:double）。但主函数中可以通过，见下
double Account::initRate() 
{
	cout << "Account::initRate()" << endl;
	return 2.0;
}

//所有的静态成员在类体外定义时都不再写static  *******重点
void Account::rate(double newRate)
{
	cout << "Account::rate(double newRate)" << endl;
	interestRate = newRate;
}


int main()
{
	Account Yang("Yang", 10); //interestRate = 2.0
	cout << Yang.applyint() << endl;
	cout << Yang.applyint() << endl << endl;//注意两个结果不一样，因为amount第一次调用之后就变了。
	
	//对interestRate赋值， 通过static成员函数
	Yang.rate(4.0);
	cout << Yang.applyint() << endl;//interestRate = 4.0
	cout << "public静态成员 " << Account::interestRate << endl; //public静态成员
	
	//对interestRate赋值 通过类名::变量名
	Account::interestRate = 3.0; //对应上面的赋值语句
	
	cout << Yang.applyint() << endl << endl;//interestRate = 3.0
	Account Ning("Ning", 200);//interestRate = 3.0
	cout << Ning.applyint() << endl << endl;
	
	//对interestRate赋值 通过对象
	Yang.interestRate = 6.0; // 也可以，并且还改了类中的静态成员值
	
	Account Pei("Pei", 2);// interestRate=6.0
	cout << Pei.applyint() << endl; 
	
	return 0;
}
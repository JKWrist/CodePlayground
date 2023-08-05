//类对象作为类成员

#include <iostream>
#include <string>

using namespace std;

class Phone
{
public:
	Phone(string pName)
	{
		cout << "phone 的有参构造调用" << endl;
		m_PhoneName = pName;
	}

	~Phone()
	{
		cout << "phone 的析构函数调用" << endl;
	}

	string m_PhoneName;
};

class Game
{
public:
	Game(string gName)
	{
		cout << "Game 的有参构造函数调用" << endl;
		m_GameName = gName;
	}

	~Game()
	{
		cout << "Game 的析构函数调用" << endl;
	}

	string m_GameName;
};


class Person
{
public:
	Person(string name, string pName, string gName) : m_Name(name), m_Phone(pName), m_Game(gName)
	{
		cout << "Person 的构造函数调用" << endl;
	}

	void PlayGame()
	{
		cout << m_Name << " 拿着 " << m_Phone.m_PhoneName << " 玩 " << m_Game.m_GameName << endl;
	}

	~Person()
	{
		cout << "Person 的析构函数调用" << endl;
	}
	
	string 	m_Name;
	Phone 	m_Phone;
	Game 	m_Game;
};

void test01()
{
	//当其他类对象，作为本类成员，先构造恰类对象，再构造自身，析构的顺序与构造顺序相反
	Person p("张三", "iphone", "原神");
	p.PlayGame();

	cout << "-------------------------------------------" << endl;

	Person p1("王五", "锤子", "王者");
	p1.PlayGame();
}

int main()
{
	test01();

	return 0;
}
//间接基类A
class A{
protected:
	int m_a;
};

//虚继承的目的是让某个类做出声明，承诺愿意共享它的基类。其中，这个被共享的基类就称为虚基类（Virtual Base Class），本例中的 A 就是一个虚基类。在这种机制下，不论虚基类在继承体系中出现了多少次，在派生类中都只包含一份虚基类的成员。

//直接基类B
class B: virtual public A
{  
//虚继承
protected:
	int m_b;
};


//直接基类C
class C: virtual public A
{  
//虚继承
protected:
	int m_c;
};


//派生类D
class D: public B, public C
{
public:
	void seta(int a){ m_a = a; }  //正确
	void setb(int b){ m_b = b; }  //正确
	void setc(int c){ m_c = c; }  //正确
	void setd(int d){ m_d = d; }  //正确
private:
	int m_d;
};

int main()
{
	//可以看到，使用多继承经常会出现二义性问题，必须十分小心。上面的例子是简单的，如果继承的层次再多一些，关系更复杂一些，程序员就很容易陷人迷魂阵，程序的编写、调试和维护工作都会变得更加困难，因此我不提倡在程序中使用多继承，只有在比较简单和不易出现二义性的情况或实在必要时才使用多继承，能用单一继承解决的问题就不要使用多继承。
	D d;
	return 0;
}
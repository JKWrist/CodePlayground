class A
{
protected:
	int m_a1;
	int m_a2;
};

class B: public A
{
protected:
	int b1;
	int b2;
};
class C: public B
{
protected:
	int c1;
	int c2;
};
class D: public C{
protected:
	int d1;
	int d2;
};
int main()
{
	A obj_a;
	B obj_b;
	C obj_c;
	D obj_d;
	return 0;
}
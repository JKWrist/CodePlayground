
//初始化 const 成员变量的唯一方法就是使用初始化列表

class VLA
{
private:
	const int m_len;
	int *m_arr;
public:
	VLA(int len);
};
//必须使用初始化列表来初始化 m_len

VLA::VLA(int len): m_len(len)
{
	m_arr = new int[len];
}


//如果写作下面的形式是错误的：
//class VLA
//{
//private:
//	const int m_len;
//	int *m_arr;
//public:
//	VLA(int len);
//};
//
//VLA::VLA(int len)
//{
//	m_len = len;
//	m_arr = new int[len];
//}
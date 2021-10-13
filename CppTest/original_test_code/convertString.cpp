//将一个字符串中的特定字符（串）替换成另一个字符(串）

void repalce_all_ditinct(string& str,const string& old_value,const string& new_value)
{
	for(string::size_type pos(0);pos!=string::npos;pos+=new_value.length()) 
	{
	if((pos=str.find(old_value,pos))!=string::npos)
		str.replace(pos,old_value.length(),new_value);
	else 
		break;
	}
}

 

//将整型转换成string类型

#include <sstream>
#include <strstream>

string IntToString(int32_t a) 
{
	string s;
	strstream ss;
	ss<<a;
	ss>>s;
	return s;
}

 

// 有时在用c++的map时，key的类型需要是一个pair，这是我们就要重载一个<运算符
//这里只举一个pair<int, int>的简单例子，可以写成模板形式以后再写

bool operator < (const pair<int32_t, int32_t> &t1,
const pair<int32_t, int32_t> &t2) 
{
	return (t1.first < t2.first) || (t1.first == t2.first &&
	t1.second < t2.second);
}
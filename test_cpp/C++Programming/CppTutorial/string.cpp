#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <cmath> //#include <masth.h>
#include <cstdio> //#include <stdio.h>
#include <cctype> //#include <ctype.h>
#include <cstring> //#include <string.h>
using namespace std;

void test01()
{
	string s1 = "hello world";
	string s2 = s1;
	string s3 = s1 + s2;
	string s4;

	cin >> s4;
	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl
		 << s4 << endl;
}

void test02()
{
	//读取一行中的字符串,包括空格
	string s1;
	getline(cin, s1);
	cout << s1.length() << endl;
}

//截取字符串中的子串
void test03()
{
	string s1 = "hello world";
	string s2 = s1.substr(4);	// 表示从下标4开始⼀直到结束
	string s3 = s1.substr(5, 3);//表示从下表5开始，3个字符

	cout << s1 << endl
		 << s2 << endl
		 << s3 << endl;

}

//struct
void test04()
{
	struct stu
	{
		int grade;
		float score;
	};

	stu st1;
	struct stu st2[10];
	struct stu st3;

	cout << sizeof(st1) << endl
		 << sizeof(st2) << endl
		 << sizeof(st3) << endl;
}

/****************************************************************
 *  函数名称：main
 *  创建日期：2022-06-18 17:20:59
 *  作者：xujunze
 *  输入参数：无
 *  输出参数：无
 *  返回值：无
******************************************************************/
int main()
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}

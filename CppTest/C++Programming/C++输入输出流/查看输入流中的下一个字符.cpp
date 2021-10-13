#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
string Months[12] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug", "Sep","Oct","Nov","Dec"};

int main()
{
	int c;
	//peek();返回输入流中的下一个字符
	while((c = cin.peek()) != EOF) 
	{ 
		//取输入流中的第一个字符进行查看
		int year,month,day;
		if(c >= 'A' && c <= 'Z') 
		{ 
			//美国日期格式
			string sMonth;
			cin >> sMonth >> day >> year;
			for(int i = 0;i < 12; ++i)  //查找月份
				if(sMonth == Months[i]) 
				{
					month = i + 1;
					break;
				}
		}
		else 
		{ 
			//中国日期格式
			cin >> year ;
			cin.ignore() >> month ; //用ignore跳过 "2011.12.3"中的'.'
			cin.ignore() >> day;
		}
		cin.ignore();   //跳过行末 '\n'
		cout<< setfill('0') << setw(2) << month ;//设置填充字符'\0'，输出宽度2
		cout << "-" << setw(2) << day << "-" << setw(4) << year << endl;
	}
	return 0;
}
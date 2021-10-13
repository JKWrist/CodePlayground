/*
* main.cpp
*
* Created on: 2009-7-19
*      Author: DEAN
*/

#include <iostream>
#include "CTimer.h"
#include <unistd.h>

using namespace std;

int main()
{
	CTimer t1(1,0);//,t2(1,0);    //构造函数，设两个定时器，以1秒为触发时间。参数1是秒，参数2是微秒。
	t1.StartTimer();
	//t2.StartTimer();
	sleep(1000);
	return 0;
}
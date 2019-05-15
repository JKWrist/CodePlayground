#include <iostream>
using namespace std;

struct stu
{
	int number;
	int score;
}
bool cmp(stu a, stu b)
{
	if(a.score != a.score)
		return a.score > b.score;
	else {
		return a.number < b.number;
	}
}

bool cmp (stu a, stu b)
{
	return a.score != b.score ? a.score > b.score : a.unmber < b.number; 
}
int main(int argc, char *argv[]) 
{
	
}
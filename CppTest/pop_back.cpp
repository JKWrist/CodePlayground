#include <iostream>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

int main(){
	list<int> l(5);
	iota(l.begin(),l.end(),1);
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	while (!l.empty()){
		l.pop_back();
		copy(l.begin(),l.end(),ostream_iterator<int>(cout," "));
		cout << endl;
	}
	printf("aaa %d", 1+5 > 2);
	return 0;
}
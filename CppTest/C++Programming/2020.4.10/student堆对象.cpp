#include <iostream>
#include <string.h>

#include <stdlib.h>
using namespace std;

class Student
{
public:
	Student(int id, const char * name)
	: _id(id)
	, _name(new char[strlen(name) + 1]())
	{
		strcpy(_name, name);
		cout << "Student(int, char *)" << endl;
	}
	
private:	
	~Student()
	{
		delete [] _name;
		cout << "~Student" << endl; 
	}
	
public:	
	void print() const
	{
		cout << "_id " << _id << endl
			 << "_name " << _name << endl;
	}
	
	//重载之后的new
	void * operator new(size_t size)
	{
		cout << "void * operator new(size_t)" << endl;
		void * ret = malloc(size);
		return ret;
	}
	//重载之后的delete
	void operator delete(void * ret)
	{
		cout << "void operator delete" << endl;
		free(ret);
	}
	
	void destroy()
	{
		delete this;
	}
private:
	int _id;
	char * _name;	
};

int main(int argc, char *argv[]) 
{
	Student * pstu = new Student(100, "Jack");
	pstu->print();
	pstu->destroy();
	//delete pstu;
	
	
//	Student stu1(101, "Mary"); //栈对象, 同时要求构造函数析构函数都是public的
//	stu1.print();
	
	return 0;
}
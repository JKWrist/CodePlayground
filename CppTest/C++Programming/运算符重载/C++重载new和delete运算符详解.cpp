#include <iostream>

using namespace std;

//两种重载形式的返回值相同，都是void *类型，并且都有一个参数，为size_t类型。在重载 new 或 new[] 时，无论是作为成员函数还是作为全局函数，它的第一个参数必须是 size_t 类型。size_t 表示的是要分配空间的大小，对于 new[] 的重载函数而言，size_t 则表示所需要分配的所有空间的总和。
//内存管理运算符 new、new[]、delete 和 delete[] 也可以进行重载，其重载形式既可以是类的成员函数，也可以是全局函数。一般情况下，内建的内存管理运算符就够用了，只有在需要自己管理内存时才会重载。

//以成员函数的形式重载 new 运算符：
void * className::operator new( size_t size ){
	//TODO:
}

//以全局函数的形式重载 new 运算符：
void * operator new( size_t size ){
	//TODO:
}


//同样的，delete 运算符也有两种重载形式。
//两种重载形式的返回值都是 void 类型，并且都必须有一个 void 类型的指针作为参数，该指针指向需要释放的内存空间。

//同样的，delete 运算符也有两种重载形式。以类的成员函数的形式进行重载：
void className::operator delete( void *ptr){
	//TODO:
}

//以全局函数的形式进行重载：
void operator delete( void *ptr){
	//TODO:
}


int main(int argc, char *argv[]) 
{
	
}
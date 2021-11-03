#include <iostream>
 
using namespace std;
 
class Test1
{
public:
    Test1() {cout << "Construct Test1" << endl ;} // 无参构造函数
    Test1(const Test1& t1) // 拷贝构造函数
    {
        cout << "Copy constructor for Test1" << endl ;this->a = t1.a ;
    }
    Test1& operator = (const Test1& t1) // 重载赋值运算符（也称为重载赋值函数）
    {
        cout << "assignment for Test1" << endl ;
        this->a = t1.a ;
        return *this;
    }
private:
    int a ;
};
 
//class Test2
//{
//public:
//    Test1 test1; //此处第二次调用Test 1的construct；
//    //std::cout<<"进入Test2 的构造函数"<<std::endl; //类中只能包含成员变量和成员函数！
//    Test2(Test1 &t1){test1 = t1 ;} //此处的“=”调用重载的“=”操作符；
//};
 

//第一行输出对应调用代码中第一行，构造一个Test1对象
//第三行输出对应Test2构造函数中的代码，用默认的构造函数初始化对象test1 // 这就是所谓的初始化阶段
//第四行输出对应Test2的赋值运算符，对test1执行赋值操作 // 这就是所谓的计算阶段
class Test2
{
public:
    Test1 test1 ;
    Test2(Test1 &t1)
    :test1(t1)
    {
        
    }
};

//第一行输出对应 调用代码的第一行
//第三行输出对应Test2的初始化列表，直接调用拷贝构造函数初始化test1，省去了调用默认构造函数的过程。
//也就是说，初始化的时候调用成员列表进行初始化，就不需要用自己默认的构造函数进行初始化了。这样如果有初始化列表，那么会调用拷贝构造函数进行初始化，从而省去了重载等号进行赋值的步骤，以及调用自己构造函数进行初始化的步骤。
//所以一个好的原则是，能使用初始化列表的时候尽量使用初始化列表

int main(){
    Test1 t1; //此处第一次调用Test1的construct；
    cout<<"end of fist construct t1"<<endl;
    Test2 t2(t1);
}
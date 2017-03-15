 ///
 /// @file    inherintConstructor1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 00:00:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		Base()
		{
			cout<<"Base()"<<endl;
		}
};

class Derived
: public Base
{
	public:
		//当基类没有显示定义构造函数时,创建派生类对象时
		//自动调用基类的默认构造函数
		Derived()
		{
			cout<<"Derived()"<<endl;
		}
		Derived(int i)
		{
			cout<<"Derived(int)"<<endl;
		}
};

int main(void)
{
	Derived d1;
	return 0;
}

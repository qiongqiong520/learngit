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
#if 1
		Base()
		{
			cout<<"Base()"<<endl;
		}
#endif
		Base(int i)
		{
			cout<<"Base(int)"<<endl;
		}
};
//当基类提供有参构造函数时，系统不会在提供默认构造函数
class Derived
: public Base
{
 	public:
 		//当基类有显示定义构造函数时,派生类没有显示定义
		//则创建派生类对象时，一定会调用基类的默认构造函数
		//所以必须会基类显示提供一个默认构造函
#if 0
		Derived()
		{
			cout<<"Derived()"<<endl;
		}
		Derived(int i)
		{
			cout<<"Derived(int)"<<endl;
		}
#endif
};

int main(void)
{
	Derived d1;
	return 0;
}

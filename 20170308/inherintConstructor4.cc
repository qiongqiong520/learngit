 ///
 /// @file    inherintConstructor4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 00:20:59
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
		Base(int base)
			:_base(base)
		{
			cout<<"Base(base)"<<endl;
		}
	private:
		int _base;
};

class Derived
: public Base
{
	public:
		Derived()
		:Base()//显示调用基类的午餐构造函数
		{
			cout<<"Derived()"<<endl;
		}
		Derived(int i ,int j)
			:Base(i)
			 ,_derived(j)
	{
		cout<<"Derived(int)"<<endl;
	}
	private:
		int _derived;
};

int main(void)
{
	Derived d1(1,2);

	return 0;
}


 ///
 /// @file    virtualFunc.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 20:39:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		int func(int x)
		{
			cout<<"Base ::func(int)"<<endl;
			return x;
		}
};

class Sub
: public Base
{
	 public:
	 	//virtual //派生类继承
	 		int func(int x)
			{
	 			cout<<"Sub ::func(int)"<<endl;
				return (float)x;
			}
};

int main(void)
{
 	Base base;
	base.func(1);
	Sub sub;
	sub.func(1);
	return 0;
}


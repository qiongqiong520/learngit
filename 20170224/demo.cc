 ///
 /// @file    demo.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-24 11:43:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Demo{
	public:
		//函数调用运算符
		double operator()(double x,double y)
		{
			return x>y?x:y;
		}
		double operator()(double x,double y,double z )
		{
			return (x+y)*z;
		}

	private:
};

int main(void)
{
	Demo demo;
	cout<<demo(1,2)<<endl;//函数对象

	cout<<demo(1,2,3)<<endl;
	
	return 0;
}

 ///
 /// @file    operator4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-24 23:28:50
 ///
 //运算符重载必要性
#include <iostream>
using namespace std;

class Complex
{
	//运算符重载：用户自定义数据类型的数据操作与内置的数据类型的数据操作基本一致
	//
	private:
		double real,imag;
	public:
		Complex(double r =0.0,double i =0.0)
		{
			real =r;
			imag =i;
		}
		void disp()
		{
			cout<<real<<"+"<<"i * "<<imag<<endl;//成员函数，输出负数
		}
};

int main(void)
{
	Complex cx1(1.0,2.0);
	cx1.disp();
	Complex cx2(3.0,4.0);
	cx2.disp();

	Complex c3 =cx1+cx2;
	c3.disp();
	//Complex cxRes =cx1 +cx2;//错误

	return 0;
}


///
/// @file    operator.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-25 20:28:19
///
//友元函数形式重载运算符

#include <iostream>
using namespace std;

class Complex
{
	friend Complex & operator+(const Complex&  obj1,const Complex& obj2);
	private:
	double real,imag;
	public:
	Complex(double r=0.0,double i=0.0)//构造函数，带缺省参数值
	{
		real=r;
		imag =i;
	}
#if 0
//类内成员函数形式重载
Complex operator+(const Complex&  obj1,const Complex& obj2)//加+的实现
{
	return Complex(obj1.real+obj2.real,obj1.imag+obj2.imag);
}
#endif
	void disp()
	{
	cout<<real<<" + "<<imag<<"*i"<<endl;
	}
};
//类外实现形式
#if 0
Complex operator+(const Complex&  obj1,const Complex& obj2)//加+的实现
{
	return Complex(obj1.real+obj2.real,obj1.imag+obj2.imag);
}
#endif

int main(void)
{
	Complex c1(2,3),c2(3,4),cx;
	cx =c1+c2;//相当于cx.operator+(c2)

	cx.disp();
	return 0;
}


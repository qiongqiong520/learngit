///
/// @file    complex.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-24 09:56:55
///

#include <iostream>
using std::cout;
using std::endl;

class Complex{
	public:
		friend Complex(const Complex & lhs,const Complex & rhs);
		Complex(double real,double imag)
			:_real(real)//浅拷贝
			 ,_imag(imag)
	{
		cout<<"Complex(double,double)"<<endl;
	}
		void display()
		{
			cout<<_real<<"+"<<_imag<<"i"<<endl;
		}
		//成员函数重载加法运算,严格要求左操作数是comlpex类型
		Complex operator+(const Complex & rhs)
		{
			return Complex(this->_real +rhs._real,
					this->_imag+rhs._imag);
		}
	private:
		double _real;
		double _imag;

};
#if 0
//不能对内置类型的操作符进行重载
int operator +(int a,int b){
	return a-b;
}
#endif
//自由函数
#if 0
Complex operator++(Complex & lhs=0,Complex & rhs=0)
{
	return Complex(lhs._real_rhs._real,
			lhs._imag+rhs._imag);
}
#endif

int main(void)
{
	Complex c1(1,2);
	c1.display();
	Complex c2(3,4);
	c2.display();

	Complex c3 =c1+c2;//
	c3.display();

	//c3.display();

	c3 =c1+5;//right
	return 0;
}

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
		friend Complex（const Complex & lhs,const Complex & rhs);
		Complex(double real,double imag)
			:_real(real)
				,_imag(imag)
	{
		cout<<"Complex(double,double)"<<endl;
	}
		void display()
		{
			cout<<_real<<"+"<<_imag<<endl;
		}
		//成员函数重载加法运算
Complex operator+(const Complex & rhs)
{
	return Complex(this->_real +rhs._real,
			this->_imag+rhs._iamg);
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
Complex operator+(complex & lhs,Complex & rhs)
{
	return Complex(lhs._real_rhs._real,
			lhs._imag+rhs._imag);
}
int main(void)
{
	Complex c1(1,2);
	c1.display();
	Complex c2(3,4);
	c2.display();

	return 0;
}

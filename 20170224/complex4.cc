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
			:_real(real)
				,_imag(imag)
	{
		cout<<"Complex(double,double)"<<endl;
	}
		//复合复制运算符最好一成员函数进行重载
		Complex & operator +=(const Complex & rhs)
		{
			this->_real += rhs._real;
			this->_imag +=rhs._imag;
			return *this;//如果不加引用会调用复制构造函数
		}
		//前置++的执行效率比后置++高
		Complex  & operator++()
		{//保存变化之后的值,&
			++this->_real;
			++this->_imag;
			return *this;
		}

		//后置++,参数中的int不代表参数，只是与前置++做一个区分，只是一个标志位
		Complex   operator++(int)
		{//保存变化之前的变量的值
			Complex tmp(*this);
			++this->_real;
			++this->_imag;
			return tmp;
		}
		
		void display()
		{
			cout<<_real<<"+"<<_imag<<"i"<<endl;
		}
		double getReal()const {
			return _real ;
		}
		double getImag()const
		{
			return _imag;
		}
		//成员函数重载加法运算
#if 0
		Complex operator+(const Complex & rhs)
{
	return Complex(this->getReal() +rhs.getReal(),
			this->getImag()+rhs.getIamg());
}
#endif
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
//自由函数(普通函数／全局函数)
Complex operator+(const Complex & lhs,const Complex & rhs)
{
		Complex tmp(lhs);
		tmp +=rhs;
		return tmp;
}


int main(void)
{
	int a=1,b=2;
	int c=a+b;

	a +=b;//a=a+b
	++a;//表达式值加1.a值也加一
	a++;//后置加加，表达式值为a变化之前的值，之后再做a+1，操作
		cout<<"++a"<<++a<<endl;
	cout<<"a++="<<a++<<endl;
	Complex c1(1,2);
	c1.display();

	Complex c2(3,4);
	c2.display();

	Complex c3=c1+c2;
	c3.display();

	(++c1).display();
	c1.display();

	(c1++).display();
	c1.display();

	c1 +=c2;

	return 0;
}

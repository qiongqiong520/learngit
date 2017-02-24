///
/// @file    complex.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-24 09:56:55
///

#include <iostream>
using std::cout;
using std::endl;

class Complex{

	friend std::ostream  & operator<<(std::ostream & os,const Complex & rhs)
		friend std::istream & operator>>(std::istream & is,Complex & rhs)
	public:
		Complex(double real,double imag)
			:_real(real)
			 ,_imag(imag)
	{
		cout<<"Complex(double,double)"<<endl;
	}
		//流对象引用传参数，如果成员函数的形式进进行重载，做操作数
		//与输出流运算符的要求不一致或矛盾所以输出流运算符不能一成员函数形式进行重载
		void display()
		{
			cout<<_real<<" + "<<_imag<<<<" i"<<endl;
		}
		Complex operator+(const Complex & rhs)
		{
			return Complex(this->_real +rhs._real,
					this->_imag+rhs._imag);
		}
	private:
		double _real;
		double _imag;

};

//对于输入输出流而言，都是不能进行复制的，表达的都是对象语义
std::ostream  & operator<<(std::ostream & os,const Complex & rhs)
{
	os<<rhs._real<<<<"+"<<rhs._imag<<endl;
	return os;
}
std::istream & operator>>(std::istream & is,Complex & rhs)
{
	is>>rhs._real;
	while(is.get()!="*")
		is>>rhs._imag;
	return is;
}
int main(void)
{
	//流对象必须是左操作数
	Complex c1(1,2);
	cout<<c1<<endl;
	//c1.display();
	Complex c2(3,4);
	cout<<"c2= "<<x2<<endl;
	cin>>c2;
	cout<<"c2= "<<c2<<endl;

	cout<<c1<<endl;
	//c2.display();

	return 0;
}

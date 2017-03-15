 ///
 /// @file    derivedinherit.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-08 23:37:37
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		void print()
		{
			cout<<"A::print()"<<endl;
		}
};

class B
{
	public:
		void print()
		{
			cout<<"B::print()"<<endl;
		}
};

class C
: public A
	,public B
{
	public:
		void display()
		{
			cout<<"C::display()"<<endl;
		}
};

int main(void)
{
	C c;
	cout<<"sizeof(A)="<<sizeof(A)<<endl;
	cout<<"sizeof(C)="<<sizeof(C)<<endl;
	//c.print();

	c.A::print();//解决二义性问题
	c.B::print();

	c.display();

	return 0;
}

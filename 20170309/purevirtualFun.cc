 ///
 /// @file    purevirtualFun.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 22:04:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		//声明类纯虚函数的类称为抽象类，不能实例化对象
		virtual void display()=0;//纯虚函数，没有实现只有声明

		virtual void print()=0;
};

class B:public A
{
	public:
		virtual void display()
		{
			cout<<"B::display()"<<endl;
		}
};

class C:public B
{
	public:
		virtual void print()
		{
			cout<<"C::print()"<<endl;
		}
};


int main(void)
{
	//A a;//error
	A *p =new C;
	p->display();
	p->print();


	return 0;
}

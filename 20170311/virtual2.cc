///
/// @file    virtual2.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-03-11 16:07:31
///
//测试三：多重继承（带虚函数）
//1.每个基类都有自己的虚函数表
//2.派生类如果都有自己的虚函数，会被夹到第一个虚函数表中
//3.内存布局中。其基类的布局按照虚函数表中的存放顺序存放的是
//4.派生类会覆盖基类的函数，只有第一个虚函数表中存放的对应虚函数地址，而知识一条挑战指令

#include <iostream>
using std::cout;
using std::endl;

class Base1
{
	public:
		Base1():_iBase(10){}
		virtual void f(){
			cout<<"Base::f()"<<endl;}
		virtual void g()
		{
			cout<<"Base::g()"<<endl;
		}
		virtual void h()
		{
			cout<<"Base1::h()"<<endl;
		}
	private:
		int _iBase;
};

class Base2
{
	public:
		Base2():_iBase2(10){}
		virtual void f()
		{
			cout<<"Base2::f()"<<endl;
		}

		virtual void g()
		{
			cout<<"Base2::g()"<<endl;
		}
		virtual void h()
		{
			cout<<"Base2::h()"<<endl;
		}
	private:
		int _iBase2;
};

class Base3
{
	 public:
	 	Base3():_iBase3(10)
		{
		}
		virtual void f()
		{
			cout<<"Base3::f()"<<endl;
		}
		virtual void g()
		{
			cout<<"Base3::g()"<<endl;
		}
		virtual void h()
		{
			cout<<"Base3::h()"<<endl;
		}

		private:
		int _iBase3;
};

class Derived
:public Base1,public Base2,public Base3
{
 	public:
 		Derived():_iDerived(10){}
		void f()
		{
			cout<<"Derived::f()"<<endl;
		}
		virtual void g1()
		{
			cout<<"Derived::g1()"<<endl;
		}
	private:
		int _iDerived;
};


int main(void)
{
 	Derived d;
	Base2 *pBase2=&d;
	Base3 *pBase3=&d;

	Derived *pDerived = &d;
	pBase2->f();
	
	cout<<"sizeof(d)="<<sizeof(d)<<endl;

	cout<<"&Derived = "<<&d<<endl;//三个对应地址值不样
	cout<<"*pBase2="<<pBase2<<endl;
	cout<<"*pBase3="<<pBase3<<endl;

	getchar();
	return 0;
}

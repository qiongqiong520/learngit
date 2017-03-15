 ///
 /// @file    inherintConstructor6.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 00:29:05
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		A(int ix=0)
			:_ix(ix)
		{
			cout<<"A(int)"<<endl;
		}
		~A()
		{
			cout<<"~A()"<<endl;
		}
	private:
		int _ix;
};

class B
{
	public:
	 	B(int iy=0)
			:_iy(iy)
		{
			cout<<"B(int)"<<endl;
		}
		~B()
		{
			cout<<"~B()"<<endl;
	 	}
private:
		int _iy;
};

class C
:public A
{
	public:
		C(int ix,int iy,int iz)
			:A(ix)//基类部分使用类名进行调用
			 ,_iz(iz)
  			 ,b(iy)//对象成员使用对象名进行调用
	{
		cout<<"C(int,int,int)"<<endl;
	}
		~C()
		{
			cout<<"~C()"<<endl;
		}
	private:
		B b;
  		int _iz;
};

int main(void)
{
	C c(1,2,3);
	return 0;
}


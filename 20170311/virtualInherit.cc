 ///
 /// @file    virtualInherit.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-11 15:14:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		A(int ia):_ia(ia)
	{
	}
		virtual void display()
		{
			cout<<"A::display()"<<endl;
		}
	private:
		double _ia;
};

//1.如果是虚继承，其对象布局之中又会多占一个虚基指针，
//该虚基指针默认指向虚基类的对象
//2.虚基类子对象位于派生类对象布局的末尾
//3.如果派生类没有新定义自己的虚函数，此时存储布局不会在其开始添加一个虚函数指针
//4.如果派生类有新定义自己的虚函数，则会存储器布局中的
//开始位置在添加一个虚函数指针
//5.对于gcc编译器而言，他将虚函数指针和虚基指针合并
//就是虚基函数表与虚基表合并

class B :virtual public A
{
	public:
		B(double a,double b):A(a),_ib(b)
	{
	}
		virtual void print()
		{
			cout<<"B::print()"<<endl;
		}
	private:
		double _ib;
};

int main(void)
{
	cout<<" sizeof(A)="<<sizeof(A)<<endl;
	cout<<"sizeof(B)="<<sizeof(B)<<endl;
	cout<<sizeof(double)<<endl;//默认8字节
	cout<<sizeof(long double)<<endl;//默认16字节
	return 0;
}
	

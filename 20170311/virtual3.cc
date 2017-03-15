 ///
 /// @file    virtual3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-11 20:29:30
 ///
 
//钻石型继承
//虚基指针所指向的虚基表内容
//1.虚基指针的第一条内容表示该虚基指针距离所在的字对象首地址的偏移
//2.虚基指针的第二条内容表示的是该虚基指针距离基类子对象的首地址的偏移


#pragma vtordisp(off)
#include<iostream>
using std::endl;
using std::cout;

class B
{
 	public:
 		B():_ib(10),_cb('B'){}
		virtual void f()
		{
			cout<<"B::f()"<<endl;
		}
		virtual void Bf()
		{
			cout<<"B::bf()"<<endl;
		}
	private:
		int _ib;
		char _cb;
};

class B1:virtual public B
{
 	public:
 		B1():_ib1(100),_cb1('1'){}
#if 1
		virtual void f()
		{cout<<"B::f1()"<<endl;}
#endif
		virtual void Bf1()
		{
			cout<<"B1::Bf1()"<<endl;
		}

	private:
		int _ib1;
		char _cb1;
};
class B2 : virtual public B
{
 	public:
 		B2():_ib2(1000),_cb2('2'){}
#if 0 //过载 override
		virtual void f()
		{cout<<"B2::f()"<<endl;}
#endif
		virtual void Bf2()
		{cout<<"B2::Bf2()"<<endl;}
private:
		int _ib2;
		char _cb2;
};

class D:public B1,public B2
{
	public:
		D():_id(1000),_cd('3'){}
		virtual void f1()
		{cout<<"D::f1()"<<endl;}
		virtual void f2()
		{cout<<"D::f2()"<<endl;}
		virtual void Df()
		{cout<<"D::Df()"<<endl;}
	private:
		int _id;
		char _cd;
};

int main(void)
{
	D d;
	cout<<sizeof(d)<<endl;
	getchar();
	return 0;
}
		



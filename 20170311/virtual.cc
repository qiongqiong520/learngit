 ///
 /// @file    virtual.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-11 15:27:53
 ///
#if 0
#include <iostream>
using std::cout;
using std::endl;

class A
{
	int i=10;
	int ia = 100;
	void func(){}
	virtual void run() { cout<<"A::run()"<<endl;}
	virtual void run1(){cout<<"A::run1()"<<endl;}
	virtual void run2(){cout<<"A::run2()"<<endl;}
	virtual void run3(){cout<<"A::run3()"<<endl;}
};

class B:virtual public A
{
	void func(){}
	virtual void run() { cout<<"B::run()"<<endl;}
	virtual void run1(){cout<<"B::run1()"<<endl;}
	virtual void run2(){cout<<"B::run2()"<<endl;}
	virtual void run3(){cout<<"B::run3()"<<endl;}
};

class C:virtual public A
{
	void func(){}
	virtual void run() { cout<<"B::run()"<<endl;}
	virtual void run1(){cout<<"B::run1()"<<endl;}
	virtual void run2(){cout<<"B::run2()"<<endl;}
	virtual void run3(){cout<<"B::run3()"<<endl;}
};

class D:virtual public A
{
	void func(){}
	virtual void run() { cout<<"B::run()"<<endl;}
	virtual void run1(){cout<<"B::run1()"<<endl;}
	virtual void run2(){cout<<"B::run2()"<<endl;}
	virtual void run3(){cout<<"B::run3()"<<endl;}
};

int main(void)
{
	cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;
	cout<<sizeof(C)<<endl;
	cout<<sizeof(D)<<endl;

	A *pA = new D;
	D d;
	//D.run();

	typedef void(*Function)(void);
	int **pVtable =(int **)&d;

	//pVtable[0][0]
	//
	for(int idx =0;pVtable[0][idx]!=NULL;++idx)
	{
 		Function f = (Function)pVtable[0][idx];
		f();
	}
//	cout<<(int)pVtable[1]<<endl;
//	cout<<(int)pVtable[2]<<endl;

	getchar();
	return 0;
}

#endif

#include<iostream>

using std::endl;
using std::cout;

class A
{
	public:
		A():_ia(10){}
		virtual void f()
		{
			cout<<"A::f()"<<endl;
		}
	private:
		int _ia;
};

class B:virtual public A
{
	public:
		B():_ib(20){}

		void fb()
		{cout<<"B::fb()"<<endl;}

		virtual void f()
		{cout<<"B::f()"<<endl;}

		virtual void fb2()
		{cout<<"B::fb2()"<<endl;}
		
	private:
		int _ib;
};

int main(void)
{
	 cout<<sizeof(A)<<endl;
	cout<<sizeof(B)<<endl;

	B b;
	getchar();
	return 0;
}



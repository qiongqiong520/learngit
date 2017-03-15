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
		A(int ix=0)
		:_ix(ix)
		{}
		void setX(int ix)
		{
			_ix =ix;
		}

		void print()
		{
			cout<<"A::_ix"<<_ix<<endl;
		}
	protected:
		int _ix;
};

//虚继承
class B:virtual public A
{};

class C:virtual public A
{};

class D:public B,public C
{};

int main()
{
	D d;
	cout<<"sizeof(D)="<<sizeof(D)<<endl;

	d.setX(1);

	return 0;
}



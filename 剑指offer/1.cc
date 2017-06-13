 ///
 
 /// @file    1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 15:23:23
 ///
 //
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

class Base1{
	public:
		Base1(){}
		virtual ~Base1(){}
		virtual void print(){}
		virtual Base1 *clone()const{}
	protected:
		int data_Base1;
};
class Base2
{

	public:
		Base2(){}
		virtual ~Base2(){}
		virtual void print(){}
		virtual Base1 *clone()const{}
	protected:
		float data_Base2;
};
class Derived:public Base1,public Base2
{

	public:
		Derived(){}
		virtual ~Derived(){}
		virtual Derived *clone()const{}
	protected:
		static double data_Derived;
};
int main()
{
	cout<<sizeof(Derived)<<endl;
	return 0;
}

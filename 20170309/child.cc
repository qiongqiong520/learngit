 ///
 /// @file    child.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 20:51:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		virtual void display()//基类希望派生类进行覆盖
		{
			cout<<"Base::display()"<<endl;
		}
		void print()
		{
			cout<<"Base::print()"<<endl;
		}
};

class Child
:public Base
{
	public:
	 	void display()
		{
			cout<<"Child::display()"<<endl;
		}

		void print()
		{
			cout<<"Child::print()"<<endl;
		}
};

int test(void)
{
	co ut<<"sizeof(Base)="<<sizeof(Base)<<endl;
	cout<<"sizeof(Child)="<<sizeof(Child)<<endl;

	Base base;
	Base * pbase= &base;
	pbase->display();
	cout<<endl;

	Child child;
	Child *pchild=&child;
	pchild->display();
	cout<<endl;

	pbase=&child;
	pbase->display();
	pbase->print();
	cout<<endl;

	pchild =(Child*)&base;//pchild本身的本身的类型是child打印的是基类的display
	pchild->display();
	pchild->print();

	return 0;


int main(void)
{
 	Base base;
	Child child;

	Base &ref1=base;
	ref1.display();
	ref1.print();

	Base &ref2=child;
	ref2.display();//child::display()
	ref2.print();//base::print()

	return 0;
}

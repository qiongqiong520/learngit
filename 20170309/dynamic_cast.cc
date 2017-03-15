 ///
 /// @file    dynamic_cast.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 20:02:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
	 	Base(double d1)
			:_d1(d1)
		{
		}
		void display()
		{
			cout<<"Base::dispaly()"<<endl;
		}
	private:
		double _d1;
};

class Derived
: public Base
{
  	public:
  		Derived(double d1,double d2)
 			:Base(d1)
			 ,_d2(d2)
	{
	}
 		void display()
		{
 			Base::display();
			cout<<"Derived()"<<endl;
		}
	private:
		double _d2;
};

int main(void)
{
 	Base base(1);
	Base base2=base;
	base2.display();
	cout<<endl;
#if 0
	Base base3(2.2);
	base=base3;
	base.display();
	cout<<endl;

	base.display();
	Derived derived(2.2,3);//派生类子类对象
	derived.display();
	cout<<endl;
#endif

	Base *p1=&base;
	
	Derived *p2=(Derived *)p1;//p1为base类型强转为derived类型
	p2->display();

	Derived * p3=dynamic_cast<Derived*>p1;//不安全强转
	if(p3)
	{
		p3->display();
	}else{
		cout<<"类型强转不安全"<<endl;
	}

	return 0;
}

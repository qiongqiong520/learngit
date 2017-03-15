 ///
 /// @file    virtualFunc3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 21:30:26
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	 public:
	 	virtual
	 		void display()
			{
				cout<<"Base::display()"<<endl;
			}
	private:
		double _d0;
};

class Child1 :public Base
{
	public:
		void display()
		{
		cout<<"Child1::display()"<<endl;
		}
	private:
		double _d1;
};

class Child2:public Base
{
	 public:
 		void display()
		{
			cout<<"Child2::display()"<<endl;
		}
	private:
		double _d2;
};

//虚函数发生条件
//基类放定义类虚函数，派生了覆盖类基类的虚函数
//2.基类的指针或引用指向派生类对象
//3.基类的指针或引用调用虚函数
//4.中间多了一张虚表，多了一层简接性

void display(Base * pb)
{
	pb->display();
}

int main(void)
{
 	Base base;
	Child1 child2;//直接通过对象名进行调用，并不涉及到虚函数的特性，直接到方法区找相应的函数
	Child2 child1;
#if 1
	base.display();
	child2.display();//发生的是隐藏
	child1.display();
#endif

	cout<<"sizeof(Base)="<<sizeof(Base)<<endl;
	cout<<"sizeof(child2)="<<sizeof(child2)<<endl;
	cout<<"sizeof(child1)="<<sizeof(child1)<<endl;

	display(&base);
	display(&child1);
	display(&child2);

	return 0;
}


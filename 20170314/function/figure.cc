 ///
 /// @file    figure.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 19:59:24
 ///
 
#include <iostream>
#include <stdlib.h>
#include<memory>
using std::cout;
using std::endl;
using std::function;
using std::bind;

//figure是一个具体类
class Figure
{
	public:
		Figure(function<void()> cb1,function<void()> cb2)
			:_cb1(cb1),_cb2(cb2)
		{}
		void display()
		{
			if(_cb1) _cb1();
		}

		void area()
		{
			double tmp =0;
			if(_cb2)
				_cb2();
			return tmp;
		}

		void setCb1(function<void()> cb1)
		{	_cb1=cb1;	}

		void setCb2(function<void() cb2)
		{ _cb2=cb2;}

	private:
		function<void()> _cb1;
		function<void()> _cb2;
};

class Rectangle
{
	public:
		Rectangle(double a,double b)
			:_a(a),_b(b)
		{}
		void print()
		{
			cout<<"矩形";
		}
		double calcArea()
		{
			return _a*_b;
		}
	private:
		double _a;
		double _b;

};

class Circle
{
	public:
		Circle(double radius)
			:_radius(radius)
		{}
		void show()
		{
			cout<<"圆";
		}
		double clacArea()
		{return 3.14159*_radius;}
	private:
		double _radius;
};

void func(Figure & fig)
{
	fig.display();
	cout<<"的面积:"<<fig.area()<<endl;
}

int main(void)
{
	Rectangle rectangle(4,5);
	Circle circle(5);

	Figure fig(bind(&Rectangle::print,&rectangle),
			bind(&Rectangle::calcArea,&Rectangle));

	func(fig);

	fig.setCb1(bind(&Circle::show,&circle));
	fig.setCb2(bind(&Circle::area,&circle));
	
	func(fig);
}

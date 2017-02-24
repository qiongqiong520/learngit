///
/// @file    nestclass.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-24 16:21:38
///
#include"nestclass.h"
#include <iostream>
using std::cout;
using std::endl;

class Line
{
	//public:
	private:
		//换成私有类型，只能在内部使用，跟外部没有关系
		class Point{
			public:
				Point(int ix =0,int iy=0)
					:_ix(ix)
					 ,_iy(iy)
			{
			}
				void printPoint();
			private:
				int _ix;
				int _iy;
		};
	public:
		LineImpl(int x1,int y1,int x2,int y2);
		void printLine();
	private:
		Point _p1;
		Point _p2;
		Point _p3;
};

	Line::LineImpl(int x1,int y1,int x2,int y2)
	:_p1(x1,y1)
	 ,_p2(x2,y2)
{
	cout<<"Line(int,int,int,int,int)"<<endl;
}
	Line::Line(int x1,int y1,int x2,int y2)
	:_p1(x1,y1)
	 ,_p2(x2,y2)
{
	cout<<"line(int,int,int ,int)"<<endl;
}
void Line::printLine()
{
	_p1.printLine();
	cout<<"--->"<<endl;
	_p2.printLine();
}
	Line::Line(int x1,int y1,int x2,int y2)
:_pImpl(new LineImpl(x1,y1,x2,y2))
{
	cout<<"Line::LineImpl(int,int,int,int,int)"<<endl;
}
Line::~Line()
{
	cout<<"~Line()"<<endl;
	delete _pImpl;
}

int main(void)
{
	Line line(1,2,3,4);
	line.printLine();
	cout<<endl;

	Line::Point pt(5,6);
	pt.printpoint();

	cout<<endl;
	return 0;
}



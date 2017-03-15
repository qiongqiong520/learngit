 ///
 /// @file    deleter.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-07 15:54:28
 ///
#include <iostream>
#include<memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using  std::unique_ptr;

class Point
{
	public:
		Point(int ix,int iy)
			:_ix(ix)
			 ,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}
	void display()
	{
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
	//Point *addPoint(const Point* pt)
	shared_ptr<Point> addPoint(const Point * pt)
	{
		this->_ix+=pt->_ix;
		this->_iy++pt->_iy;
		return shared_ptr_from_this();
	}
	~Point()
	{
		cout<<"~Point()"<<endl
	}
	private:
		int _ix;
		int _iy;
};

int main(void)
{
	Point * pt=new Point(1,2);
	Point * pt2=new Point(3,4);


 ///
 /// @file    abuse_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-07 23:11:26
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;



class Point
:public std::enable_shared_from_this<Point>
{
 	public:
	 	Point()
		{
			cout<<"Point()"<<endl;
		}
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
		shared_ptr<Point> addPoint(const Point * pt)
		{
			this->_ix +=pt->_ix;
			this->_iy +=pt->_iy;
			return shared_from_this();
		}
		~Point()
		{
			cout<<"~Point()"<<endl;
		}
	private:
		int _ix;
		int _iy;
};

int main(void)
{
	Point *  pt =new Point(1,2);
	shared_ptr<Point> spPtr(pt);
	shared_ptr<Point> spPtr2(pt);//将一个堆对象交给两个不同的智能指针进行托管,error
	cout<<"spPtr2's use_count()="<<spPtr2.use_count()<<endl;
	
	shared_ptr<Point>spPtr3(spPtr->addPoint(spPtr2.get()));
	
	cout<<"spPtr's use_count()="<<spPtr.use_count()<<endl;
	cout<<"spPtr3's use_count()="<<spPtr3.use_count()<<endl;

#if 0
	Point *pt2=new Point(3,4);
	unique_ptr<Point> upPtr(pt2);

	unique_ptr<Point> upPtr2(pt2);
#endif

	return 0;
}

///
/// @file    Poitn.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-23 15:18:20
///
#include<math.h>
#include <iostream>
using std::cout;
using std::endl;

class Point;
//全局函数或者自由函数

class Line{
	public:
		float distance(const Point & pt1,const Point & pt2);
};

class Point{
	//全局函数值友元函数
	friend float distance(const Point &,const Point &);
	public:
	Point(int ix,int iy)//默认构造函数
		:_ix(ix)
		 ,_iy(iy){
			 cout<<"Point(int ix,int iy)"<<endl;
		 }
	//程序执行结束时，默认执行析构函数，清理栈空间
	void print()
	{
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
	private:
	int _ix;
	int _iy;
};

//全局函数或自由函数
float distance(const Point & p1,const Point & p2)
{
	return sqrt((p1._ix -p2._ix)*(p1._ix-p2._ix)+
			(p1._iy-p2._iy)*(p1._iy-p2._iy));
}

int main(void)
{
	Point pt1(1,2);
	Point pt2(3,4);
	Line line;

	pt1.print();
	cout<<"--->"<<endl;

	pt2.print();

	cout<<distance(pt1,pt2)<<endl;

	return 0;
}

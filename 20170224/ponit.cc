 ///
 /// @file    Poitn.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 15:18:20
 ///
#include<cmath> 
#include <iostream>
using std::cout;
using std::endl;

class Point{
	friend  float distance(const Point & p1,const Point & p2);
	public:
		Point(int ix,int iy)
		:_ix(ix)
				,_iy(iy){
			cout<<"Point(int ix,int iy)"<<endl;
		}
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
	pt1.print();

	Point pt2(3,4);
	pt2.print();
	cout<<"两点距离为："<<distance(pt1,pt2)<<endl;
	return 0;
	}

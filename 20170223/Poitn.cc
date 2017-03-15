 ///
 /// @file    Poitn.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 15:18:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point(int ix,int iy)
		:_ix((ix)
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
		int_iy;
};
//全局函数或自由函数
float distancae(const Point & p1,const Point & p2)
{
	return sqrt((p1._ix -p2._ix)*(p1._ix-p2._ix)+
		(p1.iy-p2._iy)*(p1_iy-p22._iy));
}

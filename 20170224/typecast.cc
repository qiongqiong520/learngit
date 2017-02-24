///
/// @file    Poitn.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-23 15:18:20
///

#include <iostream>
using std::cout;
using std::endl;

class AnotherPoint;
class Point{
	friend std::ostream &operator<<(std::ostream & os,const Point &rhs);
	public:
	Point(int ix,int iy)
		:_ix(ix)
		 ,_iy(iy){
			 cout<<"Point(int ix,int iy)"<<endl;
		 }
	//类型转换函数:有自定义类型向其他类型转换
	//1。只能是成员函数形式
	//2.没有返回值，但是必须用return语句
	//以传值方式返回一个目标类型的变量
	//3.没有参数

	operator int()
	{}
	private:
	int _ix;
	int _iy;
};

Point::operator AnotherPoint(){

	return AnotherPoint(_ix,_iy);
}
public:
	Anotherpoint(double dx,double dy)
:_dx(dx),_dy(dy)
{
}

friend std::ostream &operator<<(std::ostream & os,const AnotherPoint &rhs);
private:
double _dx;
};
//全局函数或自由函数
float distance(const Point & p1,const Point & p2)
{
	return sqrt((p1._ix -p2._ix)*(p1._ix-p2._ix)+
			(p1.iy-p2._iy)*(p1_iy-p2._iy));
}

std::ostream &operator<<(std::ostream & os,const Point &rhs)
{
	os<<"("<<rhs._ix
		<<","<<rhs._iy<<")"<<endl;
	return 0s;
}
int main(void)
{
	Point pt1(1,2);
	cout<<"y ="<<y<<endl;

	int x =pt;
	coout<"x= "<<x<<endl;

	AnotherPoint pt ;
	cout<<"ap= "<<ap<<endl;

	double y =pt;
	coout<"y= "<<y<<endl;
	cout<<"两点距离为："<<distance()<<endl;
	return 0;
}

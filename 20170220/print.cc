 ///
 /// @file    print.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 11:22:45
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		
	Point (int ix,int iy)
		:_ix(ix)//初始化列表
		,_iy(iy)
	{
	}

	void print(Point * const this) const
	{
	//	this->_ix =10;
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
	void print()
	{
		cout<<"Point::print()"<<endl;
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
	private:
	int _ix;
	int _iy;


};

int main(void)
{
	//point(1,2);不能获取临时对象

	int a=3;//通过变量a能够修改
	const int *pa = &a;//指针所致的变量内容不能修改
	*pa =10;//通过指针pa不能修改（常量指针pointer to cosnst）

	Point pt1(1,2);
	pt1.print();
	
	int b=10;
	int *const pb =&a;
	*pb =10;//right
	//pb =&b;//error
	
	cosnt Point pt1(1,2);
	pt1.print();//const 对象只能调用const成员函数

	Point pt2(2,4);//非const对象能勾访问counts成员对象
	



	return 0;
}

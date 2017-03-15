 ///
 /// @file    point3D3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-08 23:15:41
 ///
 //保护继承，子类具有部分访问基类的成员和方法的权限，子类对象没有访问基类的权限·:x
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int ix,int iy)
			:_ix(ix)
			 ,_iy(iy)
	{
		cout<<"Point(int ,int)"<<endl;
	}
		~Point()
		{
			cout<<"~Point()"<<endl;
		}

		void print()
		{
			cout<<"("<<_ix
				<<","<<_iy
				<<")"<<endl;
		}
		int getX()
		{
			return _ix;
		}

	protected:
		int getY()
		{
			return _iy;
		} 
	private:
		int _ix;
		int _iy;
};

class Point3D
: protected Point//protected继承
{
	public:
		Point3D(int ix,int iy ,int iz)
			:Point(ix,iy)
			 ,_iz(iz)
	{
		cout<<"Point3D(int,int,int)"<<endl;
	}
		~Point3D()
		{
			cout<<"~Point3D()"<<endl;
		}

		void display()
		{
			cout<<"("<<getX()//_ix基类私有成员不可以直接在派生类访问，但可以通过访问非private基类的方法来实现
				<<","<<getY()//基类protected 方法可以直接在派生类访问，表现为protected
				<<","<<_iz
 				<<")"<<endl;
 		}
	private:
 		int _iz;
};


int main(void)
{
	Point3D p3d(1,2,3);

	p3d.getX();
	p3d.display();

	Point pt(2,3);
	pt.getY();
	pt.getX();
	pt.print();
 	return 0;
}

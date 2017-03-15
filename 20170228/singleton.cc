 ///
 /// @file    singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-28 22:56:34
 ///
 //作业用模板函数写一个单例的类模板
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Singleton
{
	public:
		Singleton(){}
		~Singletong(){}
	private:
		Singleton * _pInstance;
};

template<typename T>
class Point
{
	public:
		Point(){}
		Point(int ix,int iy);
		static Point getInstance();

		~Point(){}
	private:
		int _x;
		int _y;
};

int main(void)
{
	Singleton::getInstance();

	int *p1=Singleton<int>::getInstance();
	Point *p2 = Singleton<Point>::getInstance();

	return 0;
}

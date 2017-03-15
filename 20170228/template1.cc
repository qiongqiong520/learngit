 ///
 /// @file    template1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-28 14:48:43
 ///
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point(int ix,int iy)
			:_ix(ix)
			 ,_iy(iy)
	{
	}
		friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
		friend Point operator+(const Point &lhs, const Point &rhs);
	private:
		int _ix;
		int _iy;
};

std::ostream & operator <<((std::ostream &os,const Point & rhs))
{
	os<<"("<<rhs._ix
		<<","<<rhs._iy
		<<")";
	return os;
}
Point operator+(const Point & lhs,const Point & rhs)
{
	return Point(lhs._ix+rhs._iy,lhs._iy+rhs._iy);
}
#if 1
template<typename T>
T add(T x,T y)
{
	cout<<"T add(T,T)"<<endl;
	return x+y;
}
#endif

const char * add(const char * x,const char * y)
{
	char * ptmp =new char(strlen(x)+strlen(y)+1);
	strcmp(ptmp,x);
	strcat(ptmp,y);
	return ptmp;
}

int add(int x,int y)
{
	cout<<"int add(int ,int)"<<endl;
	return x+y;
}

		
double add(double x,double y)
{
	cout<<"double add(double x,double y)"<<endl;
	return x+y;
}

template <typename T,int NUM>
T fun(T,a)
{
	return a*NUM;
}

int main(void)
{
	int a=3,b=4;
	cout<<"a+b="<<add(a,b);<<endl;

	doublr x=1.21,y=2.34;
	cout<<"x+y="<<add(x,y)<<endl;


Point operator+(const Point & lhs,const Point &rhs)
{


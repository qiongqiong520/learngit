 ///
 /// @file    template.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-28 20:40:04
 ///
#include<string.h>
#include <iostream>
using std::cout;
using std::endl;

class Point{
	public:
		Point(int ix,int iy)
			:_ix(ix),
			_iy(iy)
	{
	}
		friend std::ostream & operator<<(std::ostream &os,const Point & rhs);
		friend Point operator+(const Point &lhs,const Point &rhs);
	private:
		int _ix;
		int _iy;
};

std::ostream & operator<<(std::ostream &os,const Point &rhs)
{
	os<<"("<<rhs._ix
		<<","<<rhs._iy
		<<")"<<endl;
	return os;
}

Point operator+(const Point &lhs,const Point &rhs)
{
	return Point(lhs._ix+rhs._ix,lhs._iy+rhs._iy);
}
//函数模板，代码生成器
//函数模板定义的函数成为模板函数
#if 1
template <typename T>
T add(T x,T y)
{
	cout<<"T add(T x,T y)"<<endl;
	return x+y;
}
#endif
//当函数模板不能处理一些特殊函数类型时
//需要进行特殊处理，经过特殊处理的类型产生的函数
//叫做模板特化，特化版本的模板参数劣币啊并不需要任何类型的参数
template <>
const char * add(const char * x,const char * y)
{
	char * ptmp = new char (strlen(x)+strlen(y)+1);
	strcmp(ptmp,x);
	strcat(ptmp,y);
	return ptmp;
}
//由函数模板生成的函数，模板函数
int  add(int x,int y)
{
	cout<<"int add (int x,int y)"<<endl;
	return x+y;
}
//函数模板与普通函数可以重载
//并且普通函数的执行会有限于模板函数
double add(double x,double y)
{
	cout<<"add(double x,double y)"<<endl;
	return x+y;
}

template<typename T,int NUM>
T fun(T a){
	return a*NUM;
}

//template 的模板参数中的非类型参数只能是int
//必须在显示实例化时给出，相当于多了又一种定义的常量方式
//而且这种方式不需要修改源文
int main(void)
{
	int a=3, b=4;
	cout<<"a+b="<<add(a,b)<<endl;

	double x=1.21;
	double y =2.34;
	cout<<"x+y ="<<add(x,y)<<endl;

	return 0;
}



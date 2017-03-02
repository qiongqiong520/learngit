///
 /// @file    map.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-01 21:52:43
 ///
 
#include <iostream>
#include<string>
#include<set>

using std::cout;
using std::endl;
using std::string;
using std::set;

class Point
{
 	public:
 		Point(int ix=0,int iy=0)
		:_ix(ix)
		 ,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}
	friend std::ostream & operator <<(std::ostream & os,const Point & rhs);
	friend bool operator<(const Point &lhs,const Point & rhs);
	friend bool operator>(const Point &lhs,const Point & rhs);
	private:
	int _ix;
	int _iy;
};

std::ostream & operator<<(std::ostream & os,const Point & rhs)
{
 	os<<"("<<rhs._ix
		<<","<<rhs._iy
		<<")"<<endl;
	return os;
}
bool operator<(const Point & lhs,const Point & rhs)
{
 	if(lhs._ix<rhs._iy)
		return true;
	else
		return false;
}

bool operator>(const Point & lhs,const Point & rhs)
{
 	if(lhs._ix>rhs._iy)
		return true;
	else
		return false;
}
int main(void)
{
#if 0
 	pai r<Point,string> t(60063,"招商银行");
	cout<<t.first<<"-->"<<t.second;
#endif
	
	//map之中不能存入关键字相同的元素，默认情况小从小到大
	set<Point,std::greater<Point> > setPoint ={ 
		Point(1,2),
		Point(3,4),
		Point(5,6),
		Point(1,2)
	};
	set<Point>::iterator sit;
	for(sit=setPoint.begin();sit!=setPoint.end();++sit)
	{
		cout<<*sit<<endl;
	}
	cout<<endl;
	return 0;
}
	

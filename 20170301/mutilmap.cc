///
 /// @file    map.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-01 21:52:43
 ///
 
#include <iostream>
#include<string>
#include<map>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::multimap;

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
	multimap<Point,string,std::greater<Point> > mapPStr = {
 		pair<Point,string> (Point(1,2),"北京"),
		pair<Point,string> (Point(2,3),"上海"),
		pair<Point,string> (Point(1,2),"深圳"),
		pair<Point,string> (Point(3,4),"苏州")
	};
	for(auto &elem:mapPStr)
	{
		cout<<elem.first<<"->"<<elem.second<<endl;
	}
	cout<<endl;
	
	//map之中不能存入关键字相同的元素，默认情况小从小到大
	
	
	return 0;
}

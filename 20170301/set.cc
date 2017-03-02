 ///
 /// @file    set.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-01 16:21:52
 ///
#include<string>
#include<set>
#include <iostream>
using std::cout;
using std::endl;
using std::set;
using std::string;
#if 0
int test(void)
{
	//set之中不能存放相同的关键字,默认情况从小大到小的顺序进行排列
	
	set<int> serStr = {2,3,4,1,5,6,3,5,6};
	set<int>::iterator sit;
	for(sit = serStr.begin();sit!=setInt.end();sit++)
	{
		cout<<*sit<<" ";
	}
	cout<<endl;

	return 0;
}
#endif

class Point
{
	public:
	Point(int ix=0,int iy=0)
	:_ix(ix)
	 ,_iy(iy)
	{
		cout<<"Point(int ix,int iy)"<<endl;
	}
	friend std::ostream & operator<<(std::ostream & os,const Point & rhs);
	friend bool operator<(const Point & lhs,const Point & rhs);
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
bool operator>(const Point &lhs,const Point & rhs)
{
	if(lhs._ix>rhs._iy)
		return true;
	else
		return false;
}
#if 0
int main(void)
{//不保存重复数据,实现逆输出
   	//set之中不能存放相同的关键字
#if 0	
	set<int,std::greater<int>> serStr = {2,3,4,1,5,6,3,5,6};
	set<int>::iterator sit;
	for(sit = serStr.begin();sit!=setInt.end();sit++)
	{
		cout<<*sit<<" ";
	}
	cout<<endl;
#endif

	set<string,std::greater<string>> setStr = {"22","33","44","11","55","66","33","55","66"};
	set<string>::iterator sit;
	for(sit = setStr.begin();sit!=setStr.end();sit++)
	{
		cout<<*sit<<" ";
	}
	cout<<endl;
	return 0;
}
#endif

int main(void)
{//greater按从大到小的默认顺序实现输出
	set<Point,std::greater<Point> > setPoint = {
 		Point(1,2),
		Point(2,3),
		Point(3,4),
		Point(2,3)
	};
	set<Point>::iterator sit;
	for(sit=setPoint.begin();sit!=setPoint.end();++sit)
	{
		cout<<*sit<<endl;
	}
	cout<<endl;
	return 0;
}

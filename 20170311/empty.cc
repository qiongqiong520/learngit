 ///
 /// @file    empty.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-11 14:48:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;


//空类会占据一个字节大小
//目的是为了区分
//创建对象使不同对象
//
class Empty
{
	public: 
		void dispaly()
	{
		cout<<"Empty::dispaly()"<<endl;
	}

};
int main(void)
{
	Empty e;
	Empty e2;
	cout<<"sizeof(e)="<<sizeof(e)<<endl;
	cout<<"sizeof(e2)="<<sizeof(e2)<<endl;

	cout<<&e<<endl;
	cout<<&e2<<endl;

	e =e2;//赋值运算符函数

	Empty e3(e);//赋值构造函数
	Empty * p =new Empty;
	delete p;
	return 0;
}

 ///
 /// @file    9-1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 23:11:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int x=100;//定义性声明
int z=200;

class Example{
	int x;
	int y;
	public:
	Example(int xp=0,int yp=0)
	{
		x=xp;
		y=yp;
	}
	void print(int x){//新成员函数，型参x
		cout<<"传递来的参数:"<<x<<endl;
		cout<<"成员x:"<<(this->x)<<",成员y:"<<(this->y)<<endl;
		cout<<"除了this指针，还可以使用类名::的形式"<<endl;
		cout<<"成员x:"<<Example::x<<",成员y:"<<Example::y<<endl;
		cout<<"全局x:"<<(::x)<<endl;//访问全局变量
		cout<<"全局z:"<<z<<endl;//没有型参，谁成员对全局变量z屏蔽
	}
};

int main(void)
{
	Example ex1;//声明一个wexample类的对象exl
	ex1.print(5);//调用成员函数print（）
	return 0;
}




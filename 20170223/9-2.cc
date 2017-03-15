 ///
 /// @file    9-2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 23:24:55
 ///
 //嵌套类型（类中类），
 //如果类a定义在类b中，如果a的访问啊权限是piblic，a的作用域是b相同，不同之处在于
 //使用B：：Ad 饿形式访问A的类名，A的访问权限的private，只能在类内使用创建该类对象，无法在外部创建A类对象
 //
 //快作用域，不能在快外使用该类声明对象
#include <iostream>
using namespace std;

class line{
	//line类定义
	public:
		class point//point了定义在line类内，且为public属性，外部可访问
		{
			private:
				//point类内私有成员列表
				int x;
				int y;
			public:
				point(int xp=0,int  yp=0)
int main(void)
{
		


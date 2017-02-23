 ///
 /// @file    block_new.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 20:43:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	using std::cout;
	using std::endl;

	int x=20;
	{
		cout<<"x="<<x<<endl;
		int y= 100;//内部变量有效作用域结束之前，外部变量有效作用域范围暂时被隐
		cout<<"y="<<y<<endl;
	}
int y;	
		cout<<"x="<<x<<endl;
		cout<<"y ="<<y<<endl;//the value is invalid
		return 0;
}


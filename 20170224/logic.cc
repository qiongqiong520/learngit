 ///
 /// @file    logic.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-24 10:08:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int test(void)
{
	int a=0;
	int b=0;
	if(a&&++b)//短路求值特性不再计算++b的值，执行else循环
	{//对于&&操作而言，如果左边的啊表达式诶false，右边表达式不再执行
		
		cout<<"a= "<<a<<endl;
		cout<<"b= "<<b<<endl;
	}else{
		cout<<"a= "<<a<<endl;
		cout<<"b= "<<b<<endl;
	}

	return 0;
}
int main(void)
{
	int a=1;
	int b=0;
	if(a||++b)//短路求值特性不再计算++b的值，执行else循环
	{//对于||操作而言，如果左边的表达式为true，右边表达式不再执行
		
		cout<<"a= "<<a<<endl;
		cout<<"b= "<<b<<endl;
	}else{
		cout<<"a= "<<a<<endl;
		cout<<"b= "<<b<<endl;
	}

	return 0;
}

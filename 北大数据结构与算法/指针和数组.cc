 ///
 /// @file    指针和数组.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-26 17:21:42
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int a[200];
	int *p;
	p=a;
	*(p+1)=20;//是的a[1]=20
	p[0]=30;//p[i]和*（p+i）是等效的，是的a[0]=
	p[4]=40;//使得a[4]=40;
	for(int i=0;i<10;++i)//对数组的钱10个元素进行赋值
		*(p+i)=i;
	++p;
	cout<<p[0]<<endl;//输出1 p[0]等效于*p,p[0]既是a[1]
	p=a+6;
	cout<<*p<<endl;
	return 0;
}

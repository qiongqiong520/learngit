 ///
 /// @file    7532计算浮点数相除的余数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-08 22:43:33
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	double a,b,r;
	cin>>a>>b;
	if(a>0&&b>0)
	{
 		if(b!=0)
		{
 			r=a-a/b;
			printf("%g\n",r);
		}
		else
			cout<<"error"<<endl;
	}
	else
		cout<<"error"<<endl;
	return 0;
}

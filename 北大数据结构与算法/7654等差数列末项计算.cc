 ///
 /// @file    7654等差数列末项计算.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-15 23:20:55
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int a1,a2,n;
	cin>>a1>>a2>>n;
	if(a1>=-100&&a1<=100&&a2>=-100&a2<=100)
		if(n>0&&n<=1000)
		{
			cout<<(n-1)*(a2-a1)+a1<<endl;
		}
		return 0;
}

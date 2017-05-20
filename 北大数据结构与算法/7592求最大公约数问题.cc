 ///
 /// @file    7592求最大公约数问题.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 15:52:39
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	int a,b;
	cin>>a>>b;
	cout<<gcd(a,b);
	return 0;
}

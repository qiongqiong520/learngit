 ///
 /// @file    7919数字反转.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 21:22:12
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n;
	cin>>n;
	int r=0;
	while(n){
		r=r*10+(n%10);
		n/=10;
	}
	cout<<r;
	return 0;
}

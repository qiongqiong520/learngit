 ///
 /// @file    8168乘方计算.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:18:22
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int a,n;
	cin>>a>>n;
	int v=a;
	for(int i=0;i<n-1;++i)
		v*=a;

	cout<<v;
	return 0;
}


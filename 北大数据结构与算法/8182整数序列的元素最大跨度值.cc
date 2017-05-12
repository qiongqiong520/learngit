 ///
 /// @file    8182整数序列的元素最大跨度值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:17:20
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n,x,minV,maxV;
	cin>>n>>x;
	minV=maxV=x;
	while(--n)
	{
		cin>>x;
		if(x<minV)
			minV=x;
		if(x>maxV)
			maxV = x;
		if(x>maxV)
			maxV=x;
	}
	cout<<maxV-minV;
	return 0;
}

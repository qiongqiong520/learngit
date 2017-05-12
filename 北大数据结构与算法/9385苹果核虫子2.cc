 ///
 /// @file    9385苹果核虫子2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:16:04
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	int k=y/x;
	if(y%x)
		++k;
	if(n>=k)
		cout<<n-k;
	else
		cout<<0;
	return 0;
}

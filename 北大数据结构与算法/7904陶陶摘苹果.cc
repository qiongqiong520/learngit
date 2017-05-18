 ///
 /// @file    7904陶陶摘苹果.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 09:06:08
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int a[11];
int main()
{
	for(int i=0;i<10;++i)
	
		cin>>a[i];
	int h;
	cin>>h;
	int total=0;
	for(int i=0;i<10;++i)
		if(h+30>=a[i])
			++total;
	cout<<total;
	return 0;
}

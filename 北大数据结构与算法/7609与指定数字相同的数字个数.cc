 ///
 /// @file    7609与指定数字相同的数字个数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 09:05:38
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int a[10];
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;++i)
		cin>>a[i];
	int M;
	cin>>M;
	int num=0;
	for(int i=0;i<N;++i)
		if(a[i]==M)
			++num;
	cout<<num;
	return 0;
}

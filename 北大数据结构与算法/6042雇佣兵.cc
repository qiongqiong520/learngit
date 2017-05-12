 ///
 /// @file    6042雇佣兵.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 21:22:39
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int M,N,X;
	cin>>M>>N>>X;
	while(X>0){
		int t =M/N;
		if(M%N)
			++t;
		if(X<t)
			break;
		X-=t;
		t=M/N;
		N+=t;
	}
	cout<<N;
	return 0;
}

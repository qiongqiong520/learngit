 ///
 /// @file    7905校门外的树.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 09:06:39
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

const int MX=10010;
int flags[MX];
int main()
{
	int L,M;
	for(int i=0;i<M;++i)
		flags[i]=1;
	cin>>L>>M;
	for(int i=0;i<M;++i){
		int s,e;
		cin>>s>>e;
		for(int k=s;k<=e;++k)
			flags[k]=0;
	}
	int total=0;
	for(int i=0;i<=L;++i)
		total+=flags[i];
	cout<<total;
	return 0;
}

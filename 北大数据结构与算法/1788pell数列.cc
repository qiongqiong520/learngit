 ///
 /// @file    1788pell数列.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 17:44:14
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

const int M=1000010;
int a[M];
int main()
{
	int n;
	a[1]=1;
	a[2]=2;
	for(int i=3;i<M;++i)
		a[i]=(2*a[i-1]+a[i-2])%32767;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		int k;
		cin>>k;
		cout<<a[k]<<endl;
	}
	return 0;
}

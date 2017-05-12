 ///
 /// @file    7918求特殊自然数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 21:22:28
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	for(int i=49;i<=342;++i){
		int n=i;
		int total =0;//九进制数
		int p70=n%7;
		n/=7;
		int p71=n%7;
		n/=7;
		int p72=n%7;
		if(p70*81+p71*9+p72==i){
			cout<<i<<endl;
			cout<<p72<<p71<<p70<<endl;
			cout<<p70<<p71<<p72<<endl;
			break;
			 }
	}
	return 0;
}

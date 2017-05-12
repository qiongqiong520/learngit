 ///
 /// @file    7916数字统计.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 21:22:55
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int L,R;
	int total=0;
	cin>>L>>R;
	for(int i=1;i<=R;++i){
		int n=i;
		while(n){
			if(n%10==2)
				++total;
			n/=10;
		}
	}
	cout<<total;
	return 0;
}

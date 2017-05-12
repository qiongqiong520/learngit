 ///
 /// @file    7784角谷猜想.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 21:21:50
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main(){
	long long N;
	scanf("%lld",&N);
	while(N!=1){
		long long t;
		if(N%2){
			N=N*3+1;
			printf("%lld*3+1=%lld\n",N,t);
		}
		N=t;
	}
	printf("End\n");
	return 0;
}

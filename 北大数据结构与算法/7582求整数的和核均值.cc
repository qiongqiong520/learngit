 ///
 /// @file    7582求整数的和核均值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:16:53
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n;
	scanf("%d",&n);
	int sum = 0;
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		sum+=x;
	}
	printf("%d %.5f",sum,(double)sum/n);
	return 0;
}

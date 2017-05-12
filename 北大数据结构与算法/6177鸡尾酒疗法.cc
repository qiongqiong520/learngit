 ///
 /// @file    6177鸡尾酒疗法.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:18:37
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

#define eps 1e-6
int main()
{
	int n;
	int total,valid;
	scanf("%d",&n);
	scanf("%d%d",&total,&valid);
	double x=(double)valid/total;
	while(--n){
		scanf("%d%d",&total,&valid);
		double y=(double)valid/total;
	if(y-x-0.05>eps)
		printf("better\n");
	else if(x-y-0.05>eps)
		printf("worse\n");
	else
		printf("same\n");
}
return 0;
}

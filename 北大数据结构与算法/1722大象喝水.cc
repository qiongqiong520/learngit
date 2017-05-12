 ///
 /// @file    1722大象喝水.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 16:33:20
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

#define PI 3.1415926
#define EPS 1e-8;
int main()
{
	int h,r;
	scanf("%d%d",&h,&r);
	double f =20000.0/(h*PI*r*r);
	int n=f;
	n+=(f-n)>EPS;//说不定有的编译器txt
	printf("%d",n);
	return 0;
}

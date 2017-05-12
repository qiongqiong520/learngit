 ///
 /// @file    8221计算球体积.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:02:54
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;
#define PI 3.14


int main()
{
	double r;
	scanf("%lf",&r);
	printf("%.2f",4/3.0*PI*r*r*r);
	return 0;

}

 ///
 /// @file    7520输出保留12位小数的浮点数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 17:14:50
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	double a;
	scanf("%lf",&a);
	printf("%.12f",a);
	return 0;
}

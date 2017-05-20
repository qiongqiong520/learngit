 ///
 /// @file    07输出浮点数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-19 18:42:51
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
	printf("%f\n",a);
	printf("%.5f\n",a);
	printf("%e\n",a);
	printf("%g\n",a);
	
	return 0;
}




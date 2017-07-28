 ///
 /// @file    8260计算线段长度.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-15 22:39:03
 ///
#include<stdlib.h>
#include <cstdio>
#include<cmath>
using std::abs;
int main()
{	
 	float Xa,Ya,Xb,Yb;
	scanf("%f%f%f%f",&Xa,&Ya,&Xb,&Yb);
	printf("%.3f\n",sqrt(abs(Xa-Xb)*abs(Xa-Xb)+abs(Ya-Yb*abs(Ya-Yb))));
	return 0;
}


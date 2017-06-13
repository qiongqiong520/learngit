 ///
 /// @file    1007计算余数.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-01 16:55:46
 ///
#include<stdio.h>
#include<math.h>
int main()
{   
	 double a,b,r;
	scanf("%lf  %lf",&a,&b);
	r=b-(int)a/(int)b;
	printf("%.2f\n",r);
	return 0;
} 

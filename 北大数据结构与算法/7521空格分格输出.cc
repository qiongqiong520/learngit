 ///
 /// @file    7521空格分格输出.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 18:57:33
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	char c;
	int n;
	float f;
	double d;
	scanf("%c%d%f%lf",&c,&n,&f,&d);
	printf("%c %d %.6f %.6f",c,n,f,d);
	return 0;
}

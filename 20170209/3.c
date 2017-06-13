///
/// @file    3.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-03-29 21:55:51
///
#include<stdio.h>

int func(unsigned int i) 
{
	unsigned int temp = i;
	temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa) >> 1);
	temp = (temp & 0x33333333) + ((temp & 0xcccccccc) >> 2);
	temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0) >> 4);
	temp = (temp & 0x00ff00ff) + ((temp & 0xff00ff00) >> 8);
	temp = (temp & 0x0000ffff) + ((temp & 0xffff0000) >> 16); 
	return temp;
}
int main()
{
	unsigned int a;
	a=func(0x11530828);
	printf("func(0x11530828)=%d\n",a);
	return 0;
}




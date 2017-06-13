 ///
 /// @file    1.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 10:17:25
 ///
#include<stdio.h>

int main()
{
	int i=5;
	int s=(i++)+(i++)+(i--)+(--i);
	printf("s=%d\n",s);

	return 0;
}

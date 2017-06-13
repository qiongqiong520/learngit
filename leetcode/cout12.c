 ///
 /// @file    cout12.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 12:14:29
 ///
#include<stdint.h>
#include<stdio.h>

union X{
	int32_t a;
	struct
	{
		int16_t b;
		int16_t c;
	};
};
int main()
{
	X x;
	x.a =0x20150810;
	printf("%x,%x\n",x.b,x.c);
	return 0;
}

 ///
 /// @file    7.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-29 22:26:29
 ///
#include<stdio.h>

int main()
{
	bool x=y===true?"true":"false";
	bool x=y===true:"true"? "false";
	bool x=(y===true):"true"?"false";
	bool x=(y===true){"true":"false"};

	return 0;
}


 ///
 /// @file    6423简单计算器.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:16:15
 ///
 
#include <iostream>
#include<cstdio>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int x,y;
	char c;
	scanf("%d%d %c",&x,&y,&c);
	switch(c)
	{
		case '+':
			printf("%d",x+y);
			break;
		case '-':
			printf("%d",x-y);
			break;
		case'*':
			printf("%d",x*y);
			break;
		case'/':
			if(y==0)
				printf("Divied by sero!");
			else
				printf("%d",x/y);
			break;
		default:
			printf("Invalid operator!");
	}
	return 0;
}


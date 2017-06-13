 ///
 /// @file    2.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 10:24:55
 ///
#include<stdio.h>
#define MAXSIZE 10
typedef struct {
	int  data[MAXSIZE];
	int top;
}Stack;


void InitStack(Stack s); 

int main()
{
	Stack s;
	char x,y;
	InitStack(s);
	x='n';y='g';
	Push(s,x);Push(s,'i');
	Push(s,y);
	Pop(s,x);Push(s,'r');
	Push(s,x);
	Pop(s,x);Push(s,'s');
	Pop(s,x);Push(s,'s');
	while(!Stackempty(s))
	{
		Pop(s, y);
		printf(y);
	}
	printf(x);
	return 0;
}

 ///
 /// @file    2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 15:59:50
 ///
 
#include<iostream>
#include<cstdio>
using std::cout;
using std::endl;

 int main()
{
 	int a[5]={1,2,3,4,5};
	cout<<(a+1)<<endl;

	cout<<(&a+1)-1<<endl;
	//int ptr=(int[])(&a+1);
	//printf("%d,%d",(a+1),(ptr-1));
	return 0;
}

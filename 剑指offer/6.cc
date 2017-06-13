 ///
 /// @file    6.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 16:26:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int f(int n){
	if(n==0)return 0;
	if(n==1)return 1;
	return (5*f(n-1)-6*f(n-2));
}
int main()
{
	cout<<f(6666)<<endl;
	return 0;
}

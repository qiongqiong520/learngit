 ///
 /// @file    cout.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 12:12:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int a=10;
	int b=4;
	int c=a/b;
	int d =c*a*b++;
	std::cout<<d<<endl;
	return 0;
}

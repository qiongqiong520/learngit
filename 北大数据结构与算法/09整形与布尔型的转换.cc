 ///
 /// @file    09整形与布尔型的转换.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-27 21:37:50
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	bool c;
	int a;
	cin>>a;
	c=(bool)a;
	a=c;
	cout<<a<<endl;

	return 0;
}

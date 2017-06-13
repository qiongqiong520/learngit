 ///
 /// @file    7554带余除法.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-31 23:16:51
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int dividend,divisor;
	cin>>dividend>>divisor;
	if(divisor!=0)
	{
		cout<<(dividend/divisor);
		cout<<" "<<(dividend%divisor)<<endl;
	}
	else 
		cout<<"error"<<endl;
	return 0;
}

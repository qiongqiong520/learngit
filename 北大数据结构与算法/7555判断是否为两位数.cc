 ///
 /// @file    7555判断是否为两位数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-12 00:15:32
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int a;
	cin>>a;
	if(a>=0&&a<=1000)
		if(a>=10&&a<99)
			cout<<1<<endl;
		else

			cout<<0<<endl;
	else cout<<"error"<<endl;
	return 0;
}


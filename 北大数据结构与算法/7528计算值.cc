 ///
 /// @file    7528计算值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-31 23:11:27
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	if(c!=0)
	{
		if(a>-10000&&a<10000&&b>-10000&&b<10000&&c>-10000&&c<10000)
		{
			cout<<((a+b)/c)<<endl;
		}
		else
			cout<<"error"<<endl;
	}
	else
		cout<<"error"<<endl;
	return 0;
}

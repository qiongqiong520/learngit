 ///
 /// @file    8257计算2的幂.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-31 13:30:19
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n;
	cin>>n;
	if(n>=0&&n<=31)
	{
		if(n==0)
			cout<<1<<endl;
		else if(n==1)
			cout<<2<<endl;
		else if(n>1&&n<31)
		{
			n=n-1;
			cout<<(2<<n)<<endl;
		}
		else
			cout<<(2<<n)<<endl;
	}
	return 0;
}

 ///
 /// @file    8259将一个三位数反向输出.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-06 23:02:44
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n,temp;
	cin>>n;
	if(n>=100&&n<=999)
	{
	cout<<n%100<<n%10
	}
	else
		cout<<"error"<<endl;
	return 0;
}

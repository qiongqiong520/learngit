 ///
 /// @file    8164有一门课不及格.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-12 00:10:25
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	float chinese,math;
	cin>>chinese>>math;
	if(chinese>=0&&chinese<=100&&math>=0&&math<=100)
	{
		if(chinese<60)
			if(math<60)
				cout<<0<<endl;
			else
				cout<<1<<endl;
		else if(math<60)
			cout<<1<<endl;
		else
			cout<<0<<endl;
	}
	else 
		cout<<"error"<<endl;
	return 0;
}

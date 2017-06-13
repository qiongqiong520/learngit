 ///
 /// @file    6170苹果和虫子.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-06 22:49:45
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int n,x,y,z;
	cin>>n>>x>>y;
	if(y<=n*x){
		if(y%x!=0)
			z=n-y/x-1;
		else
			z=n-y/x;
	}
		cout<<z<<endl;
	return 0;
}


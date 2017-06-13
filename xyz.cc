 ///
 /// @file    xyz.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 22:19:09
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int x,y,z;
	while(cin>>x>>y>>z){
	int a1=x+y-z;
	int b1=x*y/z;
	cout<<"a1="<<a1<<" "<<b1<<endl;

	int a2=x-z+y;
	int b2=x/z*y;
	cout<<"a2="<<a2<<" "<<b2<<endl;

	int c1=x<<y>>z;
	int d1=x&y|z;
	cout<<"c1="<<c1<<" "<<d1<<endl;

	int c2=x>>z<<y;
	int d2=x|z&y;
	cout<<"c2="<<c2<<" "<<d2<<endl;
	}
	return 0;
}

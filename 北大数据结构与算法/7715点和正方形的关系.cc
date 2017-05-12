 ///
 /// @file    7715点和正方形的关系.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-12 19:15:50
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int x,y;
	cin>>x>>y;
	if(x>-1&&x<=1&&y>=-1&&y<=-1)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}

 ///
 /// @file    7538最大数输出.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-18 23:26:41
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int a,b,c,max=0;
	cin>>a>>b>>c;
	max=a>b?(a>c?a:c):(b>c?b:c);
	cout<<max<<endl;
	return 0;
}

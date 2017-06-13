 ///
 /// @file    8217输出绝对值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-12 00:04:52
 ///
#include<cmath>
#include <iostream>
using std::cin;
using std::cout;
using std::abs;
using std::endl;
int main()
{
	float n;
	cin>>n;
	if(abs(n)<=10000)
	{
		printf("%.2f\n",abs(n));
	}else
		cout<<"error"<<endl;
	return 0;
}

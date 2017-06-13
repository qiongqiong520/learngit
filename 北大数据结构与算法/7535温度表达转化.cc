 ///
 /// @file    7535温度表达转化.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-07 23:46:37
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	double f,c;
	cin>>f;
	if(f>=-459.67)
	{
		c=5*(f-32)/9;
		printf("%.5lf\n",c);
	}
	else
		cout<<"error"<<endl;
	return 0;
}

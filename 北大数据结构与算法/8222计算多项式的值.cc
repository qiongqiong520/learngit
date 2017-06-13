 ///
 /// @file    8222计算多项式的值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-07 23:38:58
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	double a,b,c,d,x;
	double f;
	cin>>x>>a>>b>>c>>d;
	if(x>=-100&&x<=100&&a>=-100&&a<=100&&b>=-100&&b<=100&&c>=-100&&c<=100
		&&	d>=-100&&d<=100)
	{
		f=a*x*x*x+b*x*x+c*x+d;
	}
	else 
		cout<<"error"<<endl;
	printf("%.7lf\n",f);
	return 0;
}

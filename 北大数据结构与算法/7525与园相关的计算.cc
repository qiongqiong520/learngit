 ///
 /// @file    7525与园相关的计算.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-07 23:50:11
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#define PI 3.14159
int main()
{
	double r,d,circle,s;
	cin>>r;
	if(r>0&&r<=10000)
	{
		d=2*r;
		circle=2*r*PI;
		s=r*r*PI;
		printf("%.4lf %.4lf %.4lf\n",d,circle,s);
	}
	else
		cout<<"error"<<endl;
	return 0;
}


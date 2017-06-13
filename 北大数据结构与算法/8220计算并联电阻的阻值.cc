 ///
 /// @file    8220计算并联电阻的阻值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-07 23:54:45
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
 	float r1,r2;
	float R;
	cin>>r1>>r2;
	if(r1!=0&&r2!=0)
	{ if((1/r1+1/r2)!=0)
		{
	 	R=1/(1/r1+1/r2);
		printf("%.2f\n",R);
		}
		else{
			cout<<"error"<<endl;
		}
	}
	else
		cout<<"error"<<endl;
	return 0;
}

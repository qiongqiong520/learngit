 ///
 /// @file    1002三角形.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-01 16:44:40
 ///
#include <iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
int main()
{
 	int a,b,c;
	float q,sum;
	cin>>a>>b>>c;
	if(a>=1&&a<=10000&b>=1&&b<=10000&&c>=1&&c<=10000)
	{
 		if(a+b>c)
		{
	 		if(a-b<c)
			{
	 			q=(a+b+c)/2;
				sum=sqrt(q*(q-a)*(q-b)*(q-c));
				cout<<sum<<endl;
			}
			else
				cout<<"error"<<endl;
	
		}
	}
	else 
		cout<<"error"<<endl;
	return 0;
}
	

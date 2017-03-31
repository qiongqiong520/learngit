 ///
 /// @file    1016A+B.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 10:07:04
 ///
 
#include <iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	long  long num1,num2;
	int d1,d2;
	cin>>num1>>d1>>num2>>d2;
	int p1=0,p2=0;
	while(num1>0){
		if (num1%10==d1)
			p1=p1*10+d1;
		num1/=10;
	}
	while(num2>0){
	 	if(num2%10==d2)
			p2=p2*10+d2;
		num2/=10;
	}
	cout<<p1+p2<<endl;
	return 0;
}


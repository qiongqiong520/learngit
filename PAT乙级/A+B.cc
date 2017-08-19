 ///
 /// @file    A+B.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 14:14:16
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(void)
{
	int n;
	while(cin>>n){
		double a,b,c;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b>>c;
			if(a+b>c)
				cout<<"Case #"<<i+1<<":true"<<endl;
			else
				cout<<"case #"<<i+1<<":false"<<endl;
		}
	}
	return 0;
}

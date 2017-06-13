 ///
 /// @file    7582求整数的和与均值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-13 20:37:12
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int n,x,sum=0;
	cin>>n;
	if(n>=1&&n<=10000)
	 	for(int i=0;i<n;i++)
		{
	 	 	cin>>x;
			if(x>=-10000&&x<=10000)
				sum+=x;
		}
	else
		cout<<"error"<<endl;
	printf("%d %.5f\n",sum,(double)sum/n);
	return 0;
}

 ///
 /// @file    红色格子.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-16 20:34:13
 ///：wq:wq
 //
 
#include <iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int func1=1,func2=2;
	int n;
	while(cin>>n)
	{ 
		if(n==1)
			printf("%.1f\n",1);
		else if(n==2)
			printf("%.1f\n",2);
		else

			printf("%.1f\n",func(n));
	}
	return 0;
}

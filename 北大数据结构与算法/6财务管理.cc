 ///
 /// @file    6财务管理.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-13 20:25:51
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	float  surplus,sum=0;
	for(int i=0;i<12;i++)
	{
		cin>>surplus;
		if(surplus>=0&&surplus<=1000000)
			sum+=surplus;
	}
	printf("$%.2f\n",sum/12);
	return 0;
}

 ///
 /// @file    7529计算分数的浮点数值.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-31 23:22:04
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int dividend,divisor;
	scanf("%d%d",&dividend,&divisor);
	if(divisor!=0)
	{
		printf("%.9f\n",((double)dividend/(double)(divisor)));
	}
	else
		cout<<"error"<<endl;
	return 0;
}

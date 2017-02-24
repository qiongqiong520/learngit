 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-24 10:19:03
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	//sizeof是一个关键字，并不是一个函数
	int a=3;
	int b;
	cout<<sizeof(a)<<endl;
	cout<<sizeof(b)<<endl;

	printf("sizeof(a)=%lu\n",sizeof(a));
	return 0;
}

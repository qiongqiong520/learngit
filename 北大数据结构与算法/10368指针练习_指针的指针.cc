 ///
 /// @file    10368指针练习_指针的指针.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:56:34
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	int x,y,z;
	x=10;
	y=20;
	z=30;

	int * a[3]={&x,&y,&z};
	for(int **p=a;p<a+3;++p)
		cout<<*(*p)<<endl;
	return 0;
}

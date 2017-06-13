 ///
 /// @file    指针作为参数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-26 17:13:25
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int *p1,int *p2)
{
	int tmp =*p1;
	*p1=*p2;
	*p2=tmp;
}
int main()
{
	int m=3,n=4;
	swap(&m,&n);
	cout<<m<<" "<<n<<endl;
	return 0;
}

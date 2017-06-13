 ///
 /// @file    aa.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 22:13:19
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class A{
	public:
		A(int aa,int bb)
		{
			a=aa--;
			b=a*bb;
		}
	public:
		int a;
		int b;
};
int main()
{
	A x(4,5);
	cout<<x.a<<" "<<x.b<<endl;
	return 0;
}

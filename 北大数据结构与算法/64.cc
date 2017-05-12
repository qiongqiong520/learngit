 ///
 /// @file    64.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 02:09:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class A
{
	public:
		void *p1;
	private:
		void *p2;
	protected:
		void *p3;
};
class B:public A{};

int main()
{
	cout<<"sizeof(B)="<<sizeof(B)<<endl;
	return 0;
}

 ///
 /// @file    class_scope.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-24 16:10:06
 ///
 
#include <iostream>
using std::cout;
using std::endl;

namespace A
{
	int x =1;
};
namespace B
{
	int x =2;
};

class X 
{
	int ia;
};

class Y
{
	public:
		int ia;
};
int x=100;
int z= 200;
class Example
{
	public:
		Example(int a=0,int b=0)
			:x(a)
			 ,y(b)
	{}
		void print(int x)
		{
			cout<<"型参x= "<<x<<endl;
			cout<<"成员变量x = "<<this->x<<endl;
			cout<<"成员变量x = "<<Example::x<<endl;
			cout<<"全局变量x = "<<::x<<endl;
			cout<<"全局变量z= "<<z<<endl;
		}
	private:
		int x;
		int y;
};

int main(void)
{
	Example ex(1,2);
	ex.print(3);

	return 0;
}

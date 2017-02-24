 ///
 /// @file    class_scope.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-24 16:10:06
 ///
 ////9.1.cc
 
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
			cout<<"型参x= "<<x<<endl;//型参x覆盖掉成员x和全局变量x
			cout<<"成员变量x = "<<this->x<<endl;//此处y指的是成员y，如果要访问成员x，可使用this指针
			cout<<"成员变量x = "<<Example::x<<endl;//
			cout<<"全局变量x = "<<::x<<endl;//或使用类名家作用域限定符的形式知名要访问的成员x
			cout<<"全局变量z= "<<z<<endl;//没有型参、数据成员对全局变量z构成屏蔽。直接访问z即可

		}
	private:
		int x;
		int y;
};

int main(void)
{
	Example ex(1,2);
	ex.print(3);//调用成员函数

	return 0;
}

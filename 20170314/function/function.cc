 ///
 /// @file    function.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 21:03:48
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;
using std::bind;

void  printNum(int num)
{
	cout<<"num= "<<num<<endl;
}

class Foo
{
public:
	void printFoo(int num)
	{
		cout<<"Foo::printFoo num="<<num<<endl;
	}
};

int main(void)
{
	function<void(int)> f =printNum;//bind的绑定机制可以实现指定与调用实体的某些参数绑定到已有的变量。产生新的可调用实体
	//绑定参数个数不受限制
	//对于不实现绑定的参数，需要std::placehoder::_1进去，依次递增
	f(1);

	function<void()> f1= bind(printNum,100);
	f1();

	f1=bind(&Foo::printFoo,Foo(),101);
	f1();

	return 0;
}


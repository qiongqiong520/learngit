 ///
 /// @file    weak_ptr2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-07 17:12:26
 ///
 
#include <iostream>
#include<memory>

using std::cout;
using std::endl;
using std::weak_ptr;
using std::shared_ptr;

class X
{
	public:
		X()
		{
			cout<<"X()"<<endl;
		}
		~X()
		{
			cout<<"~X()"<<endl;
		}
		void fun()
		{
			cout<<"X::fun()"<<endl;
		}
};

int main(void)
{
	weak_ptr<X> p;//弱引用并不增加引用计数，只是知道该指针存在
	{
		shared_ptr<X> p2(new X);//共享智能指针
		cout<<"p2's use_count()="<<p2.use_count()<<endl;
		
		p=p2;
		cout<<"p's use_count()="<<p.use_count()<<endl;
		shared_ptr<X> p3=p.lock();//将weak_ptr提升成shared_ptr
		cout<<"p3's use_count="<<p3.use_count()<<endl;
		if(p3)
		{
			p3->fun();//权限提升成功,执行该语句
		}else{
			cout<<"X has been destroy."<<endl;
		}
	}
	//退出语句块之后x对象被销毁,p4对象返回的是一个void空指针
	cout<<"退出语句块"<<endl;

	shared_ptr<X> p4=p.lock();//提升失败
	if(p4)
	{
		p4->fun();//提升失败执行该语句
	}else{
		cout<<"X has been destory"<<endl;
	}
	
	return 0;
}

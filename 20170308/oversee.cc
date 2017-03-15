 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 00:36:15
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
	public:
		int func(int i)
		{
			return _ix;
		}
	protected:
		int _ix;
};

class Derived :public Base
{
	public:
		//发生隐藏，派生类的同名函数隐藏了基类的同名函数
		int func()
		{
			_ix = 9;//派生类的数据成员——ix隐藏来了基类数据成员
			Base::_ix = 22;
			cout<<"Base::_ix="<<Base::_ix<<endl;
			return this->_ix;
		}
	public: 
		int _ix;
};

int main(void)
{
	Derived d;
	cout<<d.func()<<endl;//发生隐藏
	cout<<d.Base::func(1)<<endl;//如果要调用基类的同名函数，必须使用

	return 0;
}

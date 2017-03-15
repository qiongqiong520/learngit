 ///
 /// @file    oversee.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-11 15:05:32
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//隐藏
//
class Base
{
	public:
	 	virtual int func(int x)
		{
			cout<<"Base::func(int)"<<endl;
			return x;
		}
};
class Sub :public Base
{
	public:
		virtual int func(float x)
		{
			cout<<"Sub::func(float)"<<endl;
			return (int)x;//类型强转
		}
};

void text(Base  & base)
{
	cout<<"x="<<base.func(5)<<endl;
}
int main(void)
{
	Base base;
	Sub sub;

	cout<<"sizeof(base)="<<sizeof(base)<<endl;
	cout<<"Sizeof(sub)="<<sizeof(sub)<<endl;

	text(base);
	text(sub);

	return 0;
}

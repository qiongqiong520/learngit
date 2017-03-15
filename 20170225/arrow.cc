 ///
 //
 /// @file    arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-25 10:07:17
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Object
{
	public:
		void func()
		{
			cout<<"Obeject::func()"<<endl;
		}
};

class MiddleObject
{
};

class ThirdObject
{
	//只能返回对象或者引用（）
	public:
		MiddleObject operator->()
		{
			return *_pmobj;
		}
	private:
		MiddleObject *_pmobj;
};

int main(void)
{
	ThirdObject tobj;
	tobj->func();

	((tobj.operator->()).operator->())
	return 0;
}

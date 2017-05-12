 ///
 /// @file    arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 03:54:58
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Object
{
	public:
		void func()
		{
			cout<<"Object::func()"<<endl;
		}
};
class MiddleObject
{
	public:
		Object * operator->()
		{
			return _pobj;
		}
	private:
		Object *_pobj;
};

class ThirdObject
{
	public:
		MiddleObject & operator->()
		{
			return *_pmobj;
		}
	private:
		MiddleObject  *_pmobj;
};

int main(void)
{
	ThirdObject tobj;
	tobj->func();

	((tobj.operator->()).operator->())->func();

	return 0;
}


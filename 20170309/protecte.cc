 ///
 /// @file    protecte.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-09 20:27:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class  A
{
	public:
		A():_ia(10)
	{}
	protected:
		int _ia;
};
class B
: public A
{
	public :
	 	void print()
		{
			cout<<"B.A::_ia="<<_ia<<endl;//_ia的访问权限是protected
		}
};
class C
: protected B
{
	public:
		void show()
		{
			cout<<"C.A::_ia="<<_ia<<endl;//_ia的访问权限是protected
		}
};

class D
:protected C
{
	 public:
 		void show()
		{
			cout<<"D.A::_ia="<<_ia<<endl;//_ia的访问权限是protecte
		}
};

int main(void)
{
	C c;
	c.show();//保护继承，子类对象不可访问基类成员方法

	D d;
	d.show();
	return 0;
}

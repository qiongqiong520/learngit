 ///
 /// @file    shared_ptr2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-07 16:13:04
 ///
 
#include <iostream>
#include<memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Parent;
class Child
{
	public:
		Child()
		{
			cout<<"Child()"<<endl;
		}
		~Child()
		{
			cout<<"~Child()"<<endl;
		}
		shared_ptr<Parent> _parentPtr;
};

class Parent
{
	public:
		Parent()
		{
			cout<<"Parent()"<<endl;
		}
		~Parent()
		{
			cout<<"~Parent()"<<endl;
		}

		shared_ptr<Child> _childPtr;
};

int test(void)
{
	//发生内存泄漏
	shared_ptr<Parent> sParent(new Parent);
	cout<<"sParent's use_count() is:"<<sParent.use_count()<<endl;
	shared_ptr<Child> sChild(new Child);
	cout<<"sChild's use_count() is:"<<sChild.use_count()<<endl;

	sParent->_childPtr=sChild;
	sChild->_parentPtr = sParent;

	cout<<"sChild's use_count()="<<sChild.use_count()<<endl;
	cout<<"sParent's use_count()="<<sParent.use_count()<<endl;

	
	return 0;
}

int main(void)
{
	test();
	return 0;
}

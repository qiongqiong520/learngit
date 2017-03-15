 ///
 /// @file    weak_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-07 16:52:26
 ///
 
#include <iostream>
#include<memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;

class Parent;//前向声明
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

		weak_ptr<Parent> _parentPtr;
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
		shared_ptr<Child> _childPtr;//weak_ptr提升为shared_ptr
};

int main(void)
{
	 //发生内存泄漏
	shared_ptr<Parent> sParent(new Parent);
	cout<<"sParent's use_count()="<<sParent.use_count()<<endl;
	shared_ptr<Child> sChild(new Child);
	cout<<"sChild's use_count()="<<sChild.use_count()<<endl;

	sParent->_childPtr = sChild;
	sChild->_parentPtr = sParent;//ptr发生内存泄漏时不会增加引用计数打破循环引用

	cout<<"sParent's use_count="<<sParent.use_count()<<endl;
	cout<<"sChild's use_count()="<<sChild.use_count()<<endl;

	return 0;
}


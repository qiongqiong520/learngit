 ///
 /// @file    singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 03:15:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//单例对象自动释放
//1.只有栈对象能够去自动调用溪沟函数
//如果在该对象的析构函数里面去执行destory函数的工作
//可以达到目的
//2.通过内部类，静态对象，解决了单例对象的自动释放问题


class Singleton
{
 	private:
	class AutoRelease
	{
	 	public:
			AutoRelease()
		{
			cout<<"AutoRelease()"<<endl;
		}
		~AutoRelease()
		{
		 	//_ix内部类不能直接外围类的静态数据成员
			cout<<"~Autorelease()"<<endl;
			if(Singleton::_pInstance)
				delete Singleton::_pInstance;
		}
	};

public:
	static Singleton * getInstance()
	{//在多线程环境下，该函数并不是线程安全的
		if(_pInstance ==NULL)
		{
			_pInstance =new Singleton;
		}
		return _pInstance;
	} 

	void print()
	{
		cout<<"Singleton::print()"<<endl;
	}

private:
 	Singleton()
	{
	 	cout<<"Singleton()"<<endl;
	}
	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}
private:
	static Singleton * _pInstance;
	static AutoRelease _ar;//——ar不能是非static的，如果是非static的
//该对象就会成为单例对象的一部分，存储在堆空间中
//也就不会有自动掉用其析构函数
//int _ix;
};

Singleton *Singleton::_pInstance =NULL;
Singleton::AutoRelease Singleton::_ar;

int main()
{
 	Singleton::getInstance()->print();
	Singleton::_pInstance;

	//Singleton::destroy();
	return 0;
}

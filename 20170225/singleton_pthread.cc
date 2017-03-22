 ///
 /// @file    singleton.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 10:08:13
 ///
#include<stdlib.h>
#include<pthread.h>
#include <iostream>

using std::cout;
using std::endl;

//单例对象自动释放
//该版本只针对linux平台有效
class Singleton
{
	public:
		static Singleton * getInstance()
		{
			pthread_once(&_once ,init);
			return _pInstance;
		}
		static void destroy()
		{
		 	if(_pInstance)
				delete _pInstance;
		}

		static void init()
		{
			_pInstance =new Singleton;
		//保证进程退出时进程会被执行一次
			atexit(destroy);
		}
	void print()
	{
		cout<<"Singleton::print()"<<endl;
	}
	private:
	Singleton(){
		cout<<"Singleton()"<<endl;
	}
	~Singleton()
	{
		cout<<"~Singleton()"<<endl;
	}
		private:
		static Singleton * _pInstance;
		static pthread_once_t _once;
};
Singleton * Singleton::_pInstance = NULL;
pthread_once_t Singleton::_once =PTHREAD_ONCE_INIT;
int main(void){
	Singleton::getInstance()->print();
	return 0;
}


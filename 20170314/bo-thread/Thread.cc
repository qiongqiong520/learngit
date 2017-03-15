 ///
 /// @file    thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 21:57:35
 ///
#include"thread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{
	Thread::Thread(ThreadCallback cb)
		:_pthId(0)
		 ,_isRunning(false)
		 ,_cb(cb)
	{}
	void Thread::start()
	{
		pthread_create(&_pthId,NULL,threadFunc,this);
		_isRunning = true;
	}

	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_join(_pthId,NULL);
			_isRunning = false;
		}
	}

	void * Thread::threadFunc(void * arg)
	{
		Thread * p=static_cast<Thread*>(arg);
		if(p)
			p->_cb();
		return NULL;
	}

	Thread::~Thread()
	{
		if(_isRunning)
		{
			pthread_detach(_pthId);
			_isRunning =false;

		}
	}
}//end of namespace wd
		

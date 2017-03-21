 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 19:34:25
 ///
 
#include"Thread.h"

namespace wd
{
	Thread::Thread(ThreadCallback cb)
		:_pthId(0)
		 ,_isRunning(0)
		 ,_cb(cb)
	{}

	Thread::~Thread()
	{
		if(_isRunning)
		{
			pthread_detach(_pthId);
			_isRunning =false;
		}

	}

	void Thread::start()
	{
		pthread_create(&_pthId,NULL,threadFunc,this);
		_isRunning =true;

	}
	void Thread::join()
	{
		if(_isRunning)
		{
			pthread_join(_pthId,NULL);
			_isRunning =false;
		}

	}
	 void * Thread::threadFunc(void * arg)
	{
		Thread * p= static_cast<Thread*>(arg);
		if(p)
			p->_cb();
		return NULL;
	}
}//end of namespace wd
	

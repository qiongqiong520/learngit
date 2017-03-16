 ///
 /// @file    Condition.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 21:39:54
 ///
 
#include "Condition.h"
#include "MutexLock.h"

namespace wd
{
	Condition::Condition(MutexLock & mutex)
		:_mutex(mutex)
	{
		pthread_cond_init(&_cond,NULL);
	}

	Condition::~Condition()
	{
		pthread_cond_destroy(&_cond);
	}

	void Condition::wait()
	{
		pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());//_mutex本身是个引用类型所以这里不需要加解引用符号
	}

	

	void Condition::notify()
	{
		pthread_cond_signal(&_cond);
	}

	void Condition::notifyall()
	{
		pthread_cond_broadcast(&_cond);
	}
}//end of namespace wd

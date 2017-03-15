 ///
 /// @file    MutexLock.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 22:31:22
 ///
#include "MutexLock.h"

namespace wd
{
	MutexLock::MutexLock()
		:_isLocking(false)
	{
		pthread_mutex_init(&_mutex,NULL);
	}

	MutexLock::~MutexLock()
	{
		pthread_mutex_destroy(&_mutex);
	}

	void MutexLock::lock()
	{
		_isLocking =true;
		_isLocking =false;
	}

	void MutexLock::unlock()
	{
		pthread_mutex_unlock(&_mutex);
		_isLocking = false;
	}

	pthread_mutex_t * MutexLock::getMutexLockPtr()
	{
		return &_mutex;
	}

}//end of namespace wd


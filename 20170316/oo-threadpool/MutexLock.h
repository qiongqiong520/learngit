 ///
 /// @file    MutexLock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 20:13:51
 ///
 
#ifndef _WD_MUTEXLOCK_H_
#define _WD_MUTEXLOCK_H_

#include "Noncopyable.h"

#include<pthread.h>

namespace wd
{

	class MutexLock
		:Noncopyable
	{
		public:
			MutexLock();
			~MutexLock();

			void lock();
			void unlock();
			pthread_mutex_t * getMutexLockPtr();
		private:
			pthread_mutex_t _mutex;
			bool _isLocking;
	};

	class MutexLockGuard
	{
		public:
			MutexLockGuard(MutexLock & mutex)
				:_mutex(mutex)
			{
				_mutex.lock();
			}
			~MutexLockGuard()
			{
				_mutex.unlock();
			}
		private:
			MutexLock & _mutex;
	};
}//end of namespace wd

#endif

 ///
 /// @file    MutexLock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-21 19:44:23
 ///
 
#ifndef __WD_MUTEXLOCK_H_
#define __WD_MUTEXLOCK_H_

#include"Noncopyable.h"
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
			MutexLock &_mutex;
	};
}//end of namespace wd
#endif

 ///
 /// @file    MutexLock.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 22:27:39
 ///
#ifndef _WD_MUTEXLOCK_H_
#define _WD_MUTEXLOCK_H_

#include"Noncopyable.h"
#include<pthread.h>

namespace wd
{
	class MutexLock
		: Noncopyable
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
}//end of namespace wd
#endif

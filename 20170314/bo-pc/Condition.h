 ///
 /// @file    Condition.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 22:51:27
 ///
 
#ifndef _WD_CONDITION_H_
#define _WD_CONDITION_H_

#include"Noncopyable.h"
#include<pthread.h>

namespace wd
{
	class MutexLock;//前向声明

	class Condition
		:Noncopyable
	{
		public:
			Condition(MutexLock & mutex);
			~Condition();

			void wait();
			void notify();
			void notifyall();
		private:
			pthread_cond_t _cond;
			MutexLock & _mutex;
	};
}//end of namespace wd

#endif

 ///
 /// @file    condition.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 17:02:11
 //
#include"mutexlock.h"
#include<pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Condition
{
	public:

		Condition(MutexLock &mutex)
			:_mutex(mutex)
		{
			pthread_cond_init(&_cond,NULL);
		}
			~Condition()
		{
			pthread_cond_destroy(&_cond);
		}

		void wait()
		{
			pthread_cond_wait(&_cond,_mutex.getMutexLockPtr());
		}

		void notify()
		{
			pthread_cond_signal(&_cond);
		}

		void notifyall()
		{

			pthread_cond_broadcast(&_cond);
		}
	private:
		Condition(const Condition

	private:
		pthread_cond_t _cond;//表现但相关联关系
		MutexLock &   _mutex;
		//MutexLock _mutex;//互斥锁不能成为条件变亮成员
		//条件变量并不负责互斥锁的生命周期
};

int main(void)
{
	MutexLock mutex;
	Condition cond(mutex);

	mutex.lock();
	cond.wait();
	cond.notify();
	mutex.unlock();

	return 0;
}


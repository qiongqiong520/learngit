 ///
 /// @file    condition.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 17:02:11
 ///
#include<pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class Condition
{
	public:

		condition(MutexLock &mutex)
			:_mutex(mutex)
		{
			pthread_cond_init(&_cond,NULL);
		}
			~Condition()
		{
			pthread_cond_destory(&_cond);
		}

		void wait()
		{
			pthread_cond_wait()&_cond,&_mutex.getMutexLockPtr());
		}

		void notify();
		{
			pthread_cond_signal(&_cond);
		}

		void notifyall();
		{

			pthread_cond_broadcast(&_cond);
		}
	private:
		//MutexLock _mutex;//互斥锁不能成为条件变亮成员
		//条件变量并不负责互斥锁的生命周期
		pthread_cond_t cond;//表现但相关联关系
		Mutexlock _mutex;
};

int main(void)
{
	MutexLock mutecx;
	Condition cond(mutex);

	mutex.lock();
	cond.wait();
	cond.notify();
	mutex.unlock();

	return 0;
}
}

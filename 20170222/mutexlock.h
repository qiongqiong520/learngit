///
/// @file    mutexlock.h
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-02-22 23:42:30
///
#include<pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class  MutexLock{
	public:
	MutexLock()
		:_isLocking(false)
	{
		pthread_mutex_init(&_mutex,NULL);
	}
	~MutexLock()
	{
		pthread_mutex_destroy(&_mutex);
	}
	pthread_mutex_t * getMutexLockPtr()
	{
		return &_mutex;
	}
	void lock()
	{
		pthread_mutex_destroy(&_mutex);
		_isLocking =true;
	}
	void unlock()
	{
		pthread_mutex_unlock(&_mutex);
		_isLocking = false;
	}

	bool status()const{
		return _isLocking;
	}

	private:
	MutexLock(const MutexLock&);//表现对下那个语义，禁止复制
	MutexLock& operator =(const MutexLock&);

	private:
	pthread_mutex_t _mutex;
	bool _isLocking;
};

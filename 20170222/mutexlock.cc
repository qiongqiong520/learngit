 ///
 /// @file    mutexlock.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 16:47:28
 ///
#include<pthread.h> 
#include <iostream>
using std::cout;
using std::endl;

class MutexLock{
	public:
MutexLock()
{
	pthread_mutex_init(&_mutex,NULL);
}
~MutexLock()
{
	pthread_mutex_destory(&mutex);
}

void lock()
{
	pthread_mutex_lock(&_mutex);
_isLocking =true;
}
void unlock()
{
pthread_mutex_unlock(&_mutex);
_isLocking =false;
}

bool status() const{
	return _isLocking;
}
private:
MutexLock(const MutexLock&);//表现对象欲以
MutexLock operator & =

privatae:
pthread_mutex_t _mutex;
bool _isLocking;
};


int main(void)
{
	//值语义，能够进行复制
	int a=3;
	int b=a;
	MutexLock mutex;//系统资源，表现对象语义,唯一不能进行复制
	mutex.lock();
	mutex.unlock();

	MutexLock mutex2(mutex); //需要被禁止,编译不能通过，不能在类之外进行调用


	return 0；

}


 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 19:30:18
 ///
 
#include "Noncopyable.h"

#include<pthread.h>

#include<functional>
using std::function;

namespace wd
{
	class Thread
		:private Noncopyable//实现继承
		 //：public Noncopyable//接口继承
	{
		typedef function<void()> ThreadCallback;
		public:
		Thread(ThreadCallback cb);
		~Thread();

		void start();
		void join();

		static void *threadFunc(void * arg);

		private:
		pthread_t _pthId;
		bool _isRunning;
		ThreadCallback _cb;//回调函数
	};
}//end of namespace wd

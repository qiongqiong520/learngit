 ///
 /// @file    thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 21:52:01
 ///
 //
 //
 //
#ifndef _WD_THREAD_H_
#define _WD_THREAD_H_

#include"Noncopyable.h"
#include<pthread.h>

#include<functional>
using std::function;

namespace wd
{
	class Thread
	:private Noncopyable//实现继承
	 //:public Noncopyable//接口继承
	{
		typedef function<void()> ThreadCallback;
		public:
			Thread(ThreadCallback cb);
			~Thread();

			void start();
			void join();

			static void * threadFunc(void * arg);//原本为两个参数,其中一个参数为空,故选择静态

		private:
 	 		pthread_t _pthId;
			bool _isRunning;
			ThreadCallback _cb;//回调函数
	};
}//namespace wd end

#endif

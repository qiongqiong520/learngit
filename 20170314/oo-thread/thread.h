 ///
 /// @file    thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 21:52:01
 ///
#include"Noncopyable.h"
#include<pthread.h>

namespace wd
{
	class Thread
	:private Noncopyable//实现继承
	 //:public Noncopyable//接口继承
	{
		public:
			Thread();
			virtual ~Thread();

			virtual void run() =0;

			void start();
			void join();

			static void * threadFunc(void * arg);//原本为两个参数,其中一个参数为空,故选择静态

		private:
			pthread_t _pthId;
			bool _isRunning;
	};
}//namespace wd end

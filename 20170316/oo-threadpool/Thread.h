 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 20:38:36
 ///
 
#ifndef _WD_THREAD_H_
#define _WD_THREAD_H_

#include"Noncopyable.h"
#include<pthread.h>
#include<vector>
namespace wd
{
	class Thread
		:private Noncopyable//实现继承
		 //:public Noncopyable //接口继承
	{
		public:
 			Thread();
			virtual  ~Thread();

			virtual void run()=0;

			void start();
			void join();

			static void * threadFunc(void * arg);
		private:
 	 		pthread_t _pthId;
			bool _isRunning;
	};
}//end of namespace wd
#endif



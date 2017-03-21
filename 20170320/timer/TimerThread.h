 ///
 /// @file    TimerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 20:02:14
 ///
 
#ifndef __WD_TIMERTHREAD_H_
#define __WD_TIMERTHREAD_H_

#include"Timer.h"
#include"Thread.h"


namespace wd
{
	class TimerThread
	{
		public:
			typedef std::function<void()> TimerCallback;
			TimerThread(int initTime,int intervalTime,TimerCallback cb);

			~TimerThread();

			void start();
			void stop();

		private:
			Timer _timer;
			Thread _thread;
	};
}//end of namespace wdd
#endif 

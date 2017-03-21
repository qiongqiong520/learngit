 ///
 /// @file    Timer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 18:44:33
 ///
 
#ifndef __WD_TIMER_H_
#define __WD_TIMER_H_

#include"Noncopyable.h"
#include <functional>

namespace wd
{
	class Timer:public Noncopyable
	{
		
		typedef std::function<void()> TimerCallback;
		public:
		Timer(int initTime,int intervalTime ,TimerCallback cb);
		~Timer();

		void start();
		void stop();
		bool isStarting() const
		{
			return _isStarted;
		}
		private:
		int createTimerFd();
		void setTimerFd(int iniTime,int intervalTime);
		void stopTimerFd();
		void readTimerFd();
		private:
		int _fd;
		int _initTime;
		int _intervalTime;
		TimerCallback _cb;
		bool _isStarted;
	};
}//end of namespacce wd
#endif

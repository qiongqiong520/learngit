 ///
 /// @file    Eventfd.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 17:38:46
 ///
#ifndef __WD_EVENTFD_H_
#define __WD_EVENTFD_H_
#include"Noncopyable.h"

#include<functional>

namespace wd
{
	class Eventfd:public Noncopyable
	{
		typedef std::function<void()> EventfdCallback;

		public:
		Eventfd(EventfdCallback cb);
		~Eventfd();

		void start();
		void stop();
		bool isStarting() const
		{
			return _isStarted;	
		}

		void wakeup();

		private:
		int createEventFd();
		void handleRead();
		private:
		int _fd;
		EventfdCallback _cb;
		bool _isStarted;
	};
}//end of namepace wd

#endif

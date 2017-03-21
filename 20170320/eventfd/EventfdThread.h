 ///
 /// @file    EventfdThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 21:13:26
 ///
 
#ifndef __WD_EVENTFDTHREAD_H_
#define __WD_EVENTFDTHREAD_H_

#include"Eventfd.h"
#include "Thread.h"

namespace wd
{
	class EventfdThread
	{
		public:
			typedef std::function<void()> EventfdCallback;
			EventfdThread(EventfdCallback cb);

			~EventfdThread();

			void start();
			void stop();
			void wakeup();

		private:
			Eventfd _event;
			Thread _thread;
	};
}//end of namespace wd
#endif

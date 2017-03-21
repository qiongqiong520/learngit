 ///
 /// @file    EventfdThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 21:17:28
 ///

#include"EventfdThread.h"

#include<iostream>

using std::endl;
using std::cout;

namespace wd
{
	EventfdThread::EventfdThread(EventfdCallback cb)
		:_event(cb)
		 ,_thread(std::bind(&Eventfd::start,&_event))
	{
	}
	EventfdThread::~EventfdThread()
	{
		if(_event.isStarting())
			stop();
	}

	void EventfdThread::start()
	{
		_thread.start();
	}

	void EventfdThread::stop()
	{
		if(_event.isStarting())
			_event.stop();
		_thread.join();
	}

	void EventfdThread::wakeup()
	{
		_event.wakeup();
	}
}//end of namespace wd

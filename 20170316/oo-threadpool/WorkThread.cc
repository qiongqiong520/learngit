 ///
 /// @file    WorkerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 22:23:31
 ///

#include"WorkThread.h"
#include "Threadpool.h"

namespace wd
{
	WorkThread::WorkThread(Threadpool & threadpool)
		:_threadpool(threadpool)
	{}

	void WorkThread::run()
	{
		_threadpool.processTask();
	}
}//end of namespace wd

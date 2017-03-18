 ///
 /// @file    Threadpool.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 20:51:27
 ///


#ifndef _WD_THREADPOOL_H_
#define _WD_THREADPOOL_H_

#include"Buffer.h"

#include<vector>
#include<memory>

using std::vector;
using std::shared_ptr;

namespace wd
{

	class Thread;
	class Threadpool
	{
		friend class WorkerThread;
		public:
			Threadpool(size_t threadnum,size_t bufSize);
			~Threadpool();

			void start();
			void stop();

			void addTask(Task *);
		private:
			Task * getTask();
			void processTask();
		private:
			bool _isExit;
			size_t _threadNum;
			size_t _bufSize;
			Buffer _buff;
			vector<shared_ptr<Thread> > _threads;
	};
}//end of namespace wd

#endif 

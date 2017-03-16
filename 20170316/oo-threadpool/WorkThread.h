 ///
 /// @file    WorkerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 21:05:11
 ///
 
#ifndef _WD_WORKTHREAD_H_
#define _WD_WORKTHREAD_H_

#include"Thread.h"

#include<iostream>

using std::cout;
using std::endl;

namespace wd
{
 	class Threadpool;
	class WorkThread:public Thread
	{
 		public:
 			WorkThread(Threadpool & threadpool);
			void run();

			~WorkThread()
			{
				cout<<"~WorkThread()"<<endl;
			}
		private:
			Threadpool & _threadpool;
	};
}//end of namespace wd
#endif

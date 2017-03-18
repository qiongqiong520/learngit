 ///
 /// @file    Threadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 22:10:07
 ///
#include"Threadpool.h"
#include"WorkThread.h"
#include"Task.h"
#include<unistd.h>


namespace wd
{
	Threadpool::Threadpool(size_t threadNum,size_t bufSize)
		:_isExit(false)
		 ,_threadNum(threadNum)
		 ,_bufSize(bufSize)
		 ,_buff(bufSize)
	{
		_threads.reserve(_threadNum);
	}

	Threadpool::~Threadpool()
	{
		if(!_isExit)
			stop();
	}

	void Threadpool::start()
	{
 		for(size_t idx=0;idx!=_threadNum;++idx)
		{
	 		Thread * p= new WorkThread(*this);
			shared_ptr<Thread> sp(p);
			_threads.push_back(sp);
			sp->start();
		}
	}

	void Threadpool::stop()
	{
 	 	if(!_isExit)
		{
 	 		//等待人物队列的任务z执行完毕
			while(!_buff.empty())
			{
				sleep(1);
			}
			_isExit =true;//标志线程池要退出
			_buff.wakeup();
			for(auto & elem:_threads){
	 		 	elem->join();
				cout<<"thread 's use cout() = "<<elem.use_count()<<endl;//use_count()引用计数
			}
			_threads.clear();
		}
	}

	void Threadpool::addTask(Task * ptask)
	{
		_buff.push(ptask);
	}

	Task * Threadpool::getTask()
	{
		return _buff.pop();//真正阻塞在这里
	}

	void Threadpool::processTask()
	{
		while(!_isExit)
		{
			Task * ptask =getTask();//当任务队列为空时，每个线程都阻塞在gettask方法上
			if(ptask)
				ptask->excute();
		}
	}
}//end of namespace wd
	


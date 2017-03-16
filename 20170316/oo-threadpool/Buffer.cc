 ///
 /// @file    Buffer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 21:25:14
 ///
 
#include"Buffer.h"

#include<iostream>
using std::cout;
using std::endl;

namespace wd
{
	Buffer::Buffer(size_t size)
		:_mutex()
		 ,_notEmpty(_mutex)
		 ,_notFull(_mutex)
		 ,_size(size)
		 ,_flag(true)
	{

	}

	bool Buffer::empty()
	{
		return _que.size()==0;
	}
	bool Buffer::full()
	{
		return _que.size()==_size;
	}

	//push方法运行在生产者线程中
	void Buffer::push(ElemType elem)
	{
	 	MutexLockGuard guard(_mutex);
		while(full())
 			_notFull.wait();//等待条件变量，使用while可以避免条件变量被异常唤醒

		_que.push(elem);
		_notEmpty.notify();
	}
	//pop方法运行砸消费者线程
	ElemType Buffer::pop()
	{
 	 	MutexLockGuard guard(_mutex);
		while(_flag && empty())
			_notEmpty.wait();//条件变量

		if(_flag)
		{
	 		ElemType ret=_que.front();
			_que.pop();
			_notFull.notify();
			return ret;
		}else
			return NULL;
	}

	void Buffer::wakeup()
	{
 	 	_flag = false;
		_notEmpty.notifyall();
	}
}//end of namespace wd

 ///
 /// @file    Buffer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-16 19:53:52
 ///
#ifndef _WD_BUFFER_H_
#define _WD_BUFFER_H_

#include"MutexLock.h"
#include"Condition.h"

#include<queue>

namespace wd
{
class Task;

typedef Task* ElemType;

class Buffer
{
 	public:
	 	Buffer(size_t size);
		void push(ElemType elem);
		ElemType pop();
		void wakeup();
		bool empty();
		bool full();
	private:
 		MutexLock _mutex;
		Condition _notFull;
		Condition _notEmpty;
		size_t _size;
		std::queue<ElemType>_que;
		bool _flag;
};
}//end of namepsace wd

#endif

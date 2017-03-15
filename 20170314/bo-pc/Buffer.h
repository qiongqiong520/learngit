 ///
 /// @file    Buffer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 23:04:44
 ///
 
#ifndef _WD_BUFFER_H_
#define _WD_BUFFER_H_

#include "MutexLock.h"
#include"Condition.h"

#include<queue>

namespace wd
{
 	class Buffer
	{
 		public:
		Buffer(size_t size);
		void push(int);
		int pop();

		bool empty();
		bool full();

		private:
 			MutexLock _mutex;
			Condition _notEmpty;
			Condition _notFull;
			size_t _size;
			std::queue<int> _que;
	};
}//end of namespcae wd

#endif


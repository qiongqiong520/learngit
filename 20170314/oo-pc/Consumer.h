 ///
 /// @file    sconsumer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 23:19:39
 ///
 
#ifndef _WD_CONSUMER_H_
#define _WD_CONSUMER_H_

#include "Thread.h"

namespace wd
{
	class Buffer;
	class Consumer:public Thread
	{
		public:
			Consumer(Buffer & buf);
			virtual void run();
		private:
			Buffer & _buf;
	};
}//end of namespace wd

#endif

 ///
 /// @file    Producer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 22:37:20
 ///
 

#ifndef _WD_PRODUCER_H_
#define _WD_PRODUCER_H_

#include "Thread.h"

namespace wd
{
	class Buffer;
	class Producer:public Thread
	{
		public:
			Producer(Buffer &);
			virtual void run();

		private:
			Buffer & _buf;
	};

}//end of namespace wd
#endif

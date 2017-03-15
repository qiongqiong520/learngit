 ///
 /// @file    Consumer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 23:22:46
 ///
 
#include "Consumer.h"
#include "Buffer.h"

#include<unistd.h>

#include<iostream>
using std::cout;
using std::endl;

namespace wd
{
	Consumer::Consumer(Buffer & buf)
		:_buf(buf)
	{}
	void Consumer::run()
	{
		while(1)
		{
			int number=_buf.pop();
			cout<<"----consumer a number"<<number<<endl;
			sleep(1);
		}
	}
	


}//end of namespace wd

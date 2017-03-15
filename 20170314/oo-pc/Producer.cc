 ///
 /// @file    Producer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 22:46:39
 ///
 
#include"Producer.h"
#include "Buffer.h"

#include<unistd.h>
#include<stdlib.h>
#include<time.h>

#include <iostream>
using std::cout;
using std::endl;


namespace wd
{
	Producer::Producer(Buffer & buf)
		:_buf(buf)
	{}

	void Producer::run()
	{
		::srand(::time(NULL));
		while(1)
		{
			int number = ::rand()%100;
			_buf.push(number);
			cout<<"Producer a number:"<<number<<endl;
			sleep(2);
		}
	}

}//end of namespcae wd

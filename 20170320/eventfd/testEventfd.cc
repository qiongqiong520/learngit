 ///
 /// @file    testEventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 22:08:18
 ///
#include"EventfdThread.h"

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include<iostream>
#include<functional>
using std::endl;
using std::cout;
using std::bind;

class Producer
{
	public:
		void make()
		{
			::srand(::time (NULL));
			int number =::rand()%100;
			cout<<">number="<<number<<endl;
		}
};



int main(void)
{
	wd::EventfdThread event(bind(&Producer::make,Producer()));
	event.start();//创建子线程
	int cnt =20;
	while(cnt--)
	{
		::sleep(1);
		event.wakeup();
	}
	event.stop();
	return 0;
}

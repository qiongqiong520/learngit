 ///
 /// @file    textTimer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-20 20:13:55
 ///
#include"TimerThread.h"

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
			::srand(::time(NULL));
			int number =::rand()%100;
			cout<<"> number = "<<number<<endl;
		}
};


int main(void)
{
	wd::TimerThread timer(3,6,bind(&Producer::make,Producer()));

	timer.start();
	int cnt=30;
	while(cnt--)
	{
		::sleep(1);
	}

	timer.stop();
	return 0;
}

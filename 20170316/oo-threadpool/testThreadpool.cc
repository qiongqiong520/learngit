 ///
 /// @file    testThreadpool.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-17 14:22:36
 ///
 
#include "Threadpool.h"
#include "Task.h"

#include <unistd.h>
#include <stdlib.h>
#include<time.h>

#include<iostream>

using std::cout;
using std::endl;

class MyTask:public wd::Task
{
	public:
		void excute()
		{
			::srand(::time(NULL));
			int number = ::rand()%100;
			cout<<"number ="<<number<<endl;
		}
};

int main(void)
{
	shared_ptr<wd::Task> sp(new MyTask);

	wd::Threadpool threadpool(4,10);
	threadpool.start();

	int cnt=5;
	while(cnt--)
	{
		threadpool.addTask(sp.get());
		sleep(1);
	}

	threadpool.stop();

	return 0;
}

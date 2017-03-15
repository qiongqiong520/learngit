 ///
 /// @file    textBuffer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 23:56:30
 ///
 
#include"Buffer.h"
#include"Thread.h"
#include"MutexLock.h"

#include<unistd.h>
#include<stdlib.h>
#include<time.h>

#include<iostream>
#include<functional>

using std::cout;
using std::endl;
using std::bind;

wd::MutexLock mutex;

class Prodecer
{
 	public:
 		void make(wd::Buffer & buf)
		{
		::srand(time(NULL));
		while(1)
		{
	 		int number =::rand()%100;
			buf.push(number);
			mutex.lock();
			cout<<"producr a number:"<<number<<endl;
			mutex.unlock();
			sleep(1);
		}
		}
};
class Consumer
{
	public:
 		void consumer(wd::Buffer & buf)
		{
	 		while(1)
			{
	 			int number=buf.pop();
				mutex.lock();
				cout<<"-------consume a number:"<<number<<endl;
				mutex.unlock();
				sleep(2);
			}
		}
};


int main(void)
{
 	wd::Buffer buffer(10);
	wd::Thread producer(bind(&Prodecer::make,Prodecer(),std::ref(buffer)));
	wd::Thread consumer(bind(&Consumer::consumer,Consumer(),std::ref(buffer)));

	producer.start();//开启生产者线程
	consumer.start();//开启消费者线程

	producer.join();
	consumer.join();

	return 0;
}

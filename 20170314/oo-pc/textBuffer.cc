 ///
 /// @file    textBuffer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 23:56:30
 ///
 
#include "Buffer.h"
#include"Producer.h"
#include"Consumer.h"
#include<unistd.h>
#include<stdlib.h>
#include<iostream>
#include<memory>

using std::cout;
using std::endl;
using std::unique_ptr;

int main(void)
{
	wd::Buffer buffer(10);
	wd::Producer producer(buffer);
	wd::Consumer consumer(buffer);

	producer.start();//开启生产者线程
	consumer.start();//开启消费者线程

	producer.join();
	consumer.join();

	return 0;
}

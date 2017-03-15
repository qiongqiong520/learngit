 ///
 /// @file    textBuffer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 23:56:30
 ///
 
#include"Thread.h"

#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>

using std::cout;
using std::endl;

class Producer
{
  	public:
  		void func()
		{
 	 		int cnt=20;
			::srand(time(NULL));//::为全局作用域
			while(cnt--)
			{
	 	 		int number =::rand()% 100;
				cout<<"number="<<number<<endl;
				::sleep(1);
			}
		}
};

int main(void)
{
	wd::Thread thread(std::bind(&Producer::func,Producer()));
	thread.start();
	thread.join();

	return 0;
}

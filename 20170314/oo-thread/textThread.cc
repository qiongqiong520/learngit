 ///
 /// @file    textThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-14 22:13:36
 ///
#include"Thread.h"
#include<unistd.h>
#include<stdlib.h>
#include<time.h>
#include<memory>
#include <iostream>
using std::cout;
using std::endl;
using std::unique_ptr;


class DerivedThread :public wd::Thread
{
	public:
		virtual void run()
		{
			int cnt=20;
			srand(time(NULL));
			while(cnt--)
			{
				int number =rand()%100;
				cout<<"number = "<<number<<endl;
				sleep(1);
			}
		}
};

int main(void)
{
	unique_ptr<wd::Thread> p(new DerivedThread);
	p->start();
	p->join();

	return 0;
}

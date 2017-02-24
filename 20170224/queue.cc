 ///
 /// @file    queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 16:22:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Queue{
	public:
		Queue(int size)
		:_front(0)
			,_rear(0)
			,_size(size)
			,_arr(new int[_size])
		{
			
		}
		~Queue()
		{
			delete []_arr;
		}
		void push(int num)
		{
			if(!full())
			{
				_arr[_rear++]=num;
				_rear %=_size;
			}else
				cout<<"Queue is full"<<endl;
		}
		void pop(){
			if(!empty())
			{
				++_front;
				_front %=_size;
			}else
				cout<<"Queue is empty"<<endl;
		}
		bool empty()
		{
			return _front ==_rear;
		}
		bool full(){
			return (_rear+1)%_size==_front;
		}
		int front(){
			return _arr[_front];
		}
		int back(){
			return _arr[(_rear-1+_size)%_size];
		}

	private:
		int _front;
		int _rear;
		int _size;
		int *_arr;
};

int main(void)
{
	Queue queue(10);
	cout<<"队列是否为空?"<<queue.empty()<<endl;

	queue.push(1);
	cout<<"队列是否已满?"<<queue.empty()<<endl;

	for(int idx=2;idx<=10;idx++)
	{
		queue.push(idx);
	}
	cout<<"队头元素为:"<<queue.front()<<endl;

	cout<<"队列是否满?"<<queue.full()<<endl;//返回值为void型，只有0和1
	queue.pop();//队列元素不出队,输出结果异常
	queue.push(10);
	cout<<"队尾元素出队:"<<queue.back()<<endl;
#if 1
	while(!queue.empty())
	{
		cout<<queue.front()<<" ";
		queue.pop();//返回值为void

	}
#endif

	cout<<endl;
	return 0;
}

 ///
 /// @file    queque.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 14:36:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;
//使用循环数组模拟队列
class Queue{
	public:
		Queue()
		:_front(front)
		,_rear(rear)
	,_size(size)
	,_arr()
	{

	}
		~Queue()
		{
			delete [] _arr;
		}
		void push(int num){
		if(!full)){
		_arr[_rear++]=num;
		_rear %=_size;
		}else{
			cout<<"Queue is full"<<endl;
		}
		}
		void pop(){
			if(!empty()){
				++_front;
				_front %=_size;
			}else{
				cout<<"Queue is empty"<<endl;
			}
		}

		bool empty(){
			return _rear ==_front;
		}
		bool full(){
			return (_rear+1)%_size=_front;
		}
		int front(){
			return _arr[_front];
		}
		int back(){
			return _arr[(_rear -1+_size)&_size];
		}

private:
		int _front;
		int _rear;
		int _size;
		char * _arr;
};
	int main(void)
{
	Queue queue(10);
	cout<<"队列是否为空?"<<queue.empty()<<endl;
	
	queue.push(1);
	cout<<"队列队列是否为空?"<<queue.empty()<<endl;
	queue.push(1);
	
	for(int idx=2;idx<10;idx++)
	{
		queue.push(idx);
	}

	cout<<"队列中元素是否已满?"<<queue.front()<<endl;
	cout<<"队尾元素是:"<<queue.back()<<endl;

	queue.pop();
	cout<<"对头元素出队"<<queue.front()<<endl;
#if 0
	while(!queue.empty())
	{
		cout<<queue.front()<<endl;
		queue.pop();
	}
#endif

	cout<<endl;
	return 0;
}



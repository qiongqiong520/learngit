///
/// @file    templateQueue.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-03-01 20:52:29
///

#include <iostream>
using std::cout;
using std::endl;

template <typename T,int size =10>//申请10个元素的数组空间
class  Queue
{
 	public:
 		Queue();
		bool full();
		bool empty();
		void push(const T & elem);
		void pop();
		T front();
		T back();
	private:
 		T _arr[size];
		int _front;
		int _rear;
};
template<typename T,int size>
Queue<T,size>::Queue()
:_front(0)
	,_rear(0)
{
}
template<typename T,int size>
bool Queue<T,size>::empty()
{
	return _rear==_front;
}
template<typename T,int size>
bool Queue<T,size>::full()
{
	return (_rear+1)%size==_front;
}
template<typename T,int size>
void Queue<T,size>::push(const T & elem)
{
 	 if(!full())
		_arr[_rear++]=elem;
	else
		cout<<"队列为满"<<endl;
}

template<typename T,int size>
void Queue<T,size>::pop()
{
  	  if(!empty())
	{
   	 	++_front;//对头元素出队，对头++
		_front%=size;
	}
	else
		cout<<"队列为空"<<endl;
}

template<typename T,int size>
T Queue<T,size>::front()
{
	return _arr[_front];//队列非空队头元素出队
}
template<typename T,int size>
T Queue<T,size>::back()
{
	return _arr[(_rear-1+size)%size];
}
int main(void)
{
	Queue<int> queInt;
	cout<<"队列是否为空?"<<queInt.empty()<<endl;
	queInt.push(1);
	cout<<"队列是否为空?"<<queInt.empty()<<endl;

	for(int idx=2;idx!=11;++idx)//出队元素为9个
	{
		queInt.push(idx);
	}
	cout<<"队列是否已满"<<queInt.full()<<endl;
	while(!queInt.empty())
	{
		cout<<queInt.front()<<" ";
		queInt.pop();
	}
	cout<<endl;

	return 0;
}


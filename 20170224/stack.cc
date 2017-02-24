 ///
 /// @file    stack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 11:29:12
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Stack{
	public:
		Stack(int size)
			:_top(-1)
			 ,_size(size)
			 ,_arr(new int[_size])
	{

	}
		~Stack(){
			delete []_arr;
		}
		void push(int num)
		{
			if(!full()){
			_arr[++_top]=num;
			}
			else
				cout<<"stack is full"<<endl;
		}

		void pop()
		{
			if(!empty())
			{
				--_top;
			}else
				cout<<"stack is empty"<<endl;
		}
		int top(){
			return _arr[_top];
		}
		bool empty(){
			return _top =-1;
		}
		bool full(){
			return _top==(_size-1);
		}
	private:
		int _top;
		int _size;
		int * _arr;
};

int main(void)
{
	Stack stack(10);
	cout<<"当前数据是否为空？"<<stack.empty();
	cout<<endl;
	stack.push(1);
	cout<<"当前stack是否为空?"<<stack.empty()<<endl;

	for(int idx=2;idx<=10;idx++){
		stack.push(idx);
	}
	cout<<"当前的stcak是否已满?"<<stack.full()<<endl;
	//stack.pop();
	while(!stack.empty())
	{
		cout<<stack.top()<<" ";
		stack.pop();
	}
	cout<<endl;
	return 0;
}

		


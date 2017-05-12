 ///
 /// @file    templateStack.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 04:06:07
 ///
 
#include <iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

template<typename T,int size =10>

class Stack
{
	public:
		Stack();
		bool empty();
		bool full();
		bool push(const T &);
		void pop();
		const T & top() const;
	private:
		int _top;
		T _arr[size];
};
template<typename T,int size >
Stack<T,size>::Stack()
	:_top(-1)
{
}

template<typename T,int size>
bool Stack<T,size>::empty()
{
	return _top==-1;
}
template<typename T,int size>
bool Stack<T,size>::full()
{
	return _top ==size-1;
}
template<typename T,int size>
bool Stack<T,size>::push(const T & elem)
{
	if(!full())
		_arr[++_top] =elem;
	else
 		cout<<"栈已满!"<<endl;
}

template<typename T,int size>
void Stack<T,size>::pop()
{
	if(!empty())
		--_top;
	else
		cout<<"栈已空!"<<endl;
}
template<typename T,int size>
const T & Stack<T,size>::top() const
{
	return _arr[_top];
}
int main()
{
	Stack<int> stackInt;
	cout<<"此时站是否为空?"<<stackInt.empty()<<endl;
	stackInt.push(1);
	cout<<"此时栈是否为空?"<<stackInt.empty()<<endl;
	for(int idx=2;idx!=12;++idx)
	{
		stackInt.push(idx);
	}
	cout<<"此时栈是否为满？"<<stackInt.full()<<endl;
	while(!stackInt.empty())
	{
		cout<<stackInt.top()<<" ";
		stackInt.pop();
	}
	cout<<endl;
	cout<<"此时栈是否为空?"<<stackInt.empty()<<endl;

	return 0;
}

 ///
 /// @file    20170612.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-12 11:20:42
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include"../List/List.h"//以列表为基类，派生出栈模板类
template<typename T>class Stack::public List<T>{//将列表的首末端作为栈顶栈底
	public://size(),empty()以及其他开口,均可直接沿用
		void push(T const& e){insertAsList(e);}//入栈，等效于将新元素作为列表的首元素 
		T pop(){return remove(last());}//出栈：等效于删除列表的元素
		T& top(){return last()->data;}//取顶：直接返回列表的首元素
};

stackPerMutation(B[1,n]){//B[]为待甄别的输出序列，其中不含任何禁形
	Stack S;//辅助中转栈
	int i=1;//模拟输入栈A的栈顶元素
	for k=1 to n{//通过迭代，一次输出每一项B[K]
		while(S.empty()||B[k]!=S.top())//只要B[k]仍未出现在s栈顶
			S.push(i++);//就反复地从栈顶去除元素，并随即压入栈s
		//assert：只要迭代退出时，s栈必然为空，且s的栈元素就是b[k]
		//assert:以上迭代退出时，s栈必然为空，且s的栈顶元素就是B[k]
		S.pop();//因此，至此需要弹出s的栈顶元素，即为我们所希望输出的B[k]
	}
}

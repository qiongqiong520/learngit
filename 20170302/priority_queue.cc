 ///
 /// @file    priority_queue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-02 22:18:13
 ///
 

#include <iostream>
#include<queue>
#include<vector>
using std::priority_queue;
using std::vector;
using std::cout;
using std::endl;

int main(void)
{
	//优先级队列中的元素是有序的
	//默认情况下：
	//1.基础容器是vector
	//2.比较函数使用的是std::lesss
	//3.是从大到小的顺序进行排序
	//4.底层如果食用堆排序算法
	//5.如果有新的元素替换成堆顶元素；否则不替换
	int arr[10]={0,1,2,3,5,6,9,8,7,4};
	priority_queue<int,vector<int>,std::greater<int> > priQueue;
	for(size_t idx=0;idx!=11;idx++)
	{
 		priQueue.push(arr[idx]);
		cout<<"当前队列之中优先级最高的是:"<<priQueue.top()<<endl;
	}
	while(!priQueue.empty())
	{
	 		cout<<priQueue.top()<<" ";
			priQueue.pop();
		}
			cout<<endl;
			return 0;
}

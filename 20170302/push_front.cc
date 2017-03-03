 ///
 /// @file    push_front.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 14:34:30
 ///
 
#include <iostream>
#include<vector>
#include<list>
#include<deque>
using std::cout;
using std::endl;
using std::list;
using std::vector;
using std::deque;

int main()
{
	//0.定义list容器
	list<int>::iterator iter;
	int sz[5]={1,2,3,4,5};
	list<int> obL(sz,sz+5);//创建一个list对象，包含个int型元素

	//1.在容器头部插入元素
	obL.push_front(9);//将int型数据安插在容器对象头部

	//2.输出处理，看是否安插成功
	iter =obL.begin();
	while(iter!=obL.end())
	{
		cout<<(*iter)<<" ";
		iter++;//输出处理，看是否安插成功
	}
	cout<<endl;

	//3.容器头部删除元素
	obL.pop_front();//将第一个元素弹出

	//4.输出处理，看是否弹出成功
	while(iter!=obL.end())
	{
		cout<<*iter<<" ";
		iter++;
	}
	cout<<endl;

	//将定义的list容器分别改成vector和deque容器，重新测试以上代码
	//测试结果表明push_front()和pop_front()只适用于list和deque容器，不适用于list容器
getchar();

	return 0;
}

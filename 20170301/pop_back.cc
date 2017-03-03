 ///
 /// @file    pop_back.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 14:22:26
 ///
 //在容器头部插入和删除元素
#include <iostream>
#include<vector>
#include<list>
#include<deque>
using std::cout;
using std::list;
using std::endl;
using std::vector;


int main(void)
{
	//定义list容器
	list<int>::iterator iter;
	int sz[5] ={1,2,3,4,5};
	list<int> obV(sz,sz+5);//创建一个vector对象，包含3个int型元素，每个都为1
	list<int>::iterator it;
	//deque<int>::iterator it;
	//deque<int> obV(3,1);//创建一个vector对象，包含个int型元素,meige douwei
	//每个都为1
	

	//1.在尾部插入元素
	obV.push_back(2);//将int型数据安插在容器对象obv末尾

	//2.输出，看是否安插成功
	it=obV.begin();
	while(it!=obV.end())
	{
		cout<<(*it)<<" ";//输出处理，看是否弹出成功
		it++;
	}
	cout<<endl;

	//将测试结果表明push_back（）和pop_back（）同时使用这种容器
	getchar();
	return 0;
}

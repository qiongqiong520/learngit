 ///
 /// @file    deque.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 14:47:06
 ///
 //读取容器头部和尾部元素的值front，back，同时适用于list和veactor和deque三种
 //
#include <iostream>
#include<vector>
#include<list>
#include<deque>
using std::cout;
using std::endl;
using std::deque;
using std::list;
using std::vector;
#if 0
int main(void)
{
	double sz[6]={0,1,2,3,4,5,};
	deque<double> obD(sz,sz+6);

	double dFront =obD.front();//读取最前端元素的值
	double dBack =obD.back();//读取最末端元素的值

	cout<<dFront<<endl;
	cout<<dBack<<endl;

	getchar();
	return 0;
}
#endif

int main(void)
{
	//迭代器失效版本
	std::vector<std::string> vcs;
	vcs.push_back("this is A");
	std::vector<std::string>::iterator it =vcs.begin();
	int i=9;
	for(;it!=vcs.end();++it)
	{
		cout<<"capality of vector is:"<<vcs.size()<<endl;
		cout<<"-->"<<*it<<endl;//直接coredump
		if(i==9)
		{
			vcs.push_back("this is B");
			cout<<"Vcs.push"<<endl;
		}
		i=8;
	}
}

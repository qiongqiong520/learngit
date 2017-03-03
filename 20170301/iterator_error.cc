 ///
 /// @file    iterator_error.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 09:48:57
 ///
 //容器对象随着元素的插入删除自动增加或减小
#include <iostream>
#include<vector>
#include<string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

int main(void)
{
	vector<string>vecStr;
	vecStr.push_back("this is A");
	cout<<"vector'capacity= "<<vecStr.capacity()<<endl;

	//在容器遍历过程中，不要试图做添加删除数据工作
	//在容器遍历的过程会导致迭代器失效
	//
	bool flag=true;
	vector<string>::iterator it;
	for(it =vecStr.begin();
			it!=vecStr.end();++it)
	{
		cout<<"vecStr's size = "<<vecStr.size()<<endl;
		cout<<*it<<endl;
	//cout<<"flag="<<flag<<endl;
	 	if(flag)
		{
	 		vecStr.push_back("this is B");
			cout<<"vec's capacity="<<vecStr.capacity()<<endl;
			flag=false;
		}
	}
	return 0;
}

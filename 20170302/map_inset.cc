 ///
 /// @file    map_inset.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-02 16:06:56
 ///
#include <iostream>
#include<string>
#include<map>
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::multimap;
using std::pair;

//vector和deque类的容器创建后可以通过容器名
//下标或容器名.at(序号)的形式进行重载,也支持迭代器访问
//list类容器对下标运算符不支持下标运算符[]
//无法使用[]对元素进行随机访问
int text(void)
{
	map<int,string> mapInStr = {
		pair<int,string>(1,"A"),
		pair<int,string>(2,"B")
	};

	pair<int,string> t(2,"x");
	pair<map<int,string>::iterator,bool>ret = mapInStr.insert(t);
	if(ret.second)
		cout<<"数据插入成功"<<endl;
	else
	{
		cout<<"数据插入失败，原容器中已有关键字相同的元素"<<endl;
	}
	for(auto & elem:mapInStr)
	{
		cout<<elem.first<<"-->"<<elem.second<<endl;
	}
	return 0;
}

	
int main(void)
{
 	multimap<int,string> mapInStr = {
		pair<int,string>(1,"A"),
		pair<int,string>(2,"B")
	};

	pair<int,string> t(2,"x");
	multimap<int,string>::iterator ret = mapInStr.insert(t);

	for(auto & elem:mapInStr)
	{
		cout<<elem.first<<"-->"<<elem.second<<endl;
	}
	return 0;
}

	

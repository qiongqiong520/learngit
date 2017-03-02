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
int main(void)
{
	map<int,string> mapInstr = {
		pair<int,string>(1,"A"),
		pair<int,string>(2,"B")
	};

	pair<int,string> t(2,"x");
	pair<int,string::iterator,bool>ret = mapInstr.insert(t);
	if(ret.second)
		cout<<"
}

	

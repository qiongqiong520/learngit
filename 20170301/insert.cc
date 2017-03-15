 ///
 /// @file    insert.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 21:50:16
 ///
 
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;
using std::multimap;
using std::iterator;

int main(void)
{
 	pair<int,string> sz[2]={
 		pair<int,string>(1,"A"),
		pair<int,string>(2,"B")};
	pair<int,string> t(2,"X");
//ob代表关联形式容器对象
	map<int,string> obM(sz,sz+2);
	map<int,string>::iterator itM = obM.begin();//map类内迭代器
	pair<map<int,string>::iterator,bool> res=obM.insert(t);
		if(res.second)
			// 判断是否插入成功
			cout<<"插入成功"<<endl;
		else
			cout<<"map中包含关键字域与t相同的元素:"<<(*res.first).first<<" "<<(*res.first).second<<endl;
	multimap<int,string> obDM(sz,sz+2);//新申请迭代器导致院线迭代器失效，故创建新的迭代器
	multimap<int,string>::iterator idM= obDM.begin();
	idM = obDM.insert(t);//执行插入操作
	cout<<"向multimap插入元素为："<<(*idM).first<<" "<<(*idM).second<<endl;

	return 0;
}



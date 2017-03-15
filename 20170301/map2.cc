 ///
 /// @file    map2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 21:08:30
 ///
 //map容器使用：关键字不允许重复，按照关键在拍序
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;


#define T pair<int ,string>

int main(void)
{
 	//pair<int,string>
	pair<int,string> t(9,"Aisa");
	cout<<t.first<<" "<<t.second<<endl;
	//创建pair<int,string>
	
	pair<int,string>sz[4]={pair<int,string>(9,"Aisa"),pair<int,string>(4,"Africa"),
		pair<int,string>(1,"Euro"),pair<int,string>(4,"America")};
	map<int,string>obM(sz,sz+4);//用迭代器区间构造
	cout<<obM.size()<<endl;
	map<int,string>::iterator it =obM.begin();//创建map<int.string>模板类的迭代器,指向obM的头部
	while(it!=obM.end())//按顺序逐个输出obMd中的元素
	{
		cout<<(*it).first<<":"<<(*it).second<<endl;
		it++;
	}
	return 0;
}

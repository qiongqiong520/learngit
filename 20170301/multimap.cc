 ///
 /// @file    multimap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 21:37:37
 ///
 
#include <iostream>
#include<map>
using std::cout;
using std::endl;
using std::multimap;
using std::pair;
using std::string;

int main(void)
{
	pair<int,string> t(9,"Asia");
	cout<<t.first<<":"<<t.second<<endl;

	//创建pair<int,string>
	pair<int,string> sz[4]={pair<int,string>(9,"Asia"),
		pair<int,string>(4,"africa"),
		pair<int,string>(3,"America")};
	multimap<int,string> obM(sz,sz+4);//用迭代器区间构造obM
	cout<<obM.size()<<endl;//输出元素个数
	multimap<int,string>::iterator it = obM.begin();//创建map<int,stsring>模板类的迭代器，指向obM中的元素
	while(it!=obM.end())
	{
		cout<<(*it).first<<":"<<(*it).second<<endl;
		it++;
	}
	return 0;
}


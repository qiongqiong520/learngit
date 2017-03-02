 ///
 /// @file    map.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-01 21:52:43
 ///
 
#include <iostream>
#include<string>
#include<map>

using std::cout;
using std::endl;
using std::string;
using std::map;
using std::pair;

int main(void)
{
	pair<int,string> t(60063,"招商银行");
	cout<<t.first<<"-->"<<t.second;

	map<int,string> mapstr = {
 		pair<int,string>(1,"北京"),
		pair<int,string>(2,"上海"),
		pair<int,string>(3,"深圳"),
		pair<int,string>(2,"苏州")
	};
	//map之中不能存入关键字相同的元素，默认情况小从小到大
	map<int,string>::iterator mit;
	for(mit =mapstr.begin();mit !=mapstr.end();++mit)
	{
		cout<<(*mit).first<<"-->"<<(*mit).second<<endl;
	}
	cout<<endl;

	//进行查找，map可以使用数组下标访问运算符，但并不是随机访问
	cout<<mapstr[2]<<endl;
	cout<<mapstr[4]<<endl;
	mapstr[4]="上海";//添加元素
	cout<<mapstr[4]<<"-->"<<endl;

	return 0;
}

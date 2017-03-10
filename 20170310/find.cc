 ///
 /// @file    find.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-10 14:35:06
 ///
 
#include <iostream>
#include<map>
#include<set>
#include<string>
using std::cout;
using std::endl;
using std::map;
using std::set;
using std::string;


int main(void)
{
 	map<string,size_t> word_count;//empty map
	word_count["Anna"]=1;


	cout<<word_count["Anna"];
	++word_count["Anna"];
	cout<<word_count["anna"];

	//对map使用find替代下标操作
	if(word_count.find("foobar")==word_count.end())
		cout<<"foobar is not in the map"<<endl;

	//在multimap或multiset中查找元素
	
	multimap<string> search_item("Alain de Bottom");//要查找的元素
	multimap<string> authors;
	auto entries =authors.count(search_item);//元素数量
	auto iter = authors.find(search_item);//词作者的第一本书

	//用一个循环查找词作者的所有著作
	
	while(entries){
	 	cout<<iter->second<<endl;//打印每个题目
		++iter;//前进到下一本书
		--entries;//记录已经打印了多少本书
	}

	


	//关联容器访问元素
	set<int> iset={0,1,2,3,4,5,6,7,8,9};
	iset.find(1);//返回一个迭代器，指向key==1的元素
	iset.find(11);//返回一个迭代器，其值等于iset.end()
	iset.count(1);//返回1
	iset.count(11);//返回0

	
	cout<<"iset.lower_bound(5)="<<iset.lower_bound(5)<<endl;//返回一个迭代器，指向第一个关键字不小于5的元素
	cout<<"iset.upper_bound(6)="<<iset.upper_bound(6)<<endl;//返回一个迭代器，指向第一个关键字大于6的元素
	cout<<"iset.equal_range(5)="<<iset.equal_range(5)<<endl;//返回一个迭代器，表示关键字等于5的元素范围，若5不存在，pair的两个成员均等于iset.end()
	
	return 0;
}

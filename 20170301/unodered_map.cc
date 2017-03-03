///
/// @file    unodered_map.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-03-03 19:15:22
///
//nordered_map和map类似，都是存储的key-value的值，
//可以通过key快速索引到value。不同的是unordered_map
//不会根据key的大小进行排序，
#include <iostream>
#include<string>
#include<map>
using std::cout;
using std::endl;
using std::string;
using std::make_pair;
using std::map;

struct person{
	string name;
	int age;

	person(string name,int age)
	{
		this->name = name;
		this->age = age;
	}
//运算符重载tom3会把tom2覆盖掉
#if 0
	bool operator<(const person &p)const
	{
		return this->age < p.age;
	}
#endif
	bool operator <(const person & p)const{
		return this->name <p.name;
	}
};
map<person,int> m;
int main(void)
{
	 person p1("Tom1",20);  
	person p2("Tom2",22);  
	person p3("Tom3",22);  
	person p4("Tom4",23);  
	person p5("Tom5",24);  
	m.insert(make_pair(p3, 100));  
	m.insert(make_pair(p4, 100));  
	m.insert(make_pair(p5, 100));  
	m.insert(make_pair(p1, 100));  
	m.insert(make_pair(p2, 100));  
	for(map<person,int>::iterator iter=m.begin();iter !=m.end();iter++)
	{
		cout<<iter->first.name<<"\t"<<iter->first.age<<endl;
	}
	return 0;
}

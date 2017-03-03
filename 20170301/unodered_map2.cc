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
#include<unordered_map>
using namespace std;

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
	bool operator ==(const person& p)const{
		return name==p.name && age==p.age;
	}
};

size_t hash_value(const person& p)
{
  	size_t seed =0;
	std::hash_combine(seed,std::hash_value(p.name));
	std::hash_combine(seed,std::hash_value(p.age));
	return seed;
}

int main(void)
{
  	typedef std::unordered_map<person,int> umap;
	umap m;
	person p1("Tom1",20);  
	person p2("Tom2",22);  
	person p3("Tom3",22);  
	person p4("Tom4",23);  
	person p5("Tom5",24);  
	m.insert(umap::value_type(p3, 100));  
	m.insert(umap::value_type(p4, 100));  
	m.insert(umap::value_type(p5, 100));  
	m.insert(umap::value_type(p1, 100));  
	m.insert(umap::value_type(p2, 100));  
	for(umap::iterator iter=m.begin();iter !=m.end();iter++)
	{
		cout<<iter->first.name<<"\t"<<iter->first.age<<endl;
	}
	return 0;
}

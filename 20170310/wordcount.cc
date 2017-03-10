 ///
 /// @file    wordcount.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-10 14:27:38
 ///
 
#include <iostream>
#include<map>
#include<string>
using std::cout;
using std::endl;
using std::map;
using std::string;

int main(void)
{
	map<string,size_t>word_count;//empty map
	word_count["Anna"] =1;
	cout<<word_count["Anna"];//用Anna作为下标提取元素，打印1
	++word_count["Anna"];
	cout<<word_count["Anna"]<<endl;

	return 0;
}

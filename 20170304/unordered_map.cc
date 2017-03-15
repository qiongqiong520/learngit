 ///
 /// @file    unordered_map.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 11:00:54
 ///
#include<string>
#include <iostream>
#include<unordered_map>
using std::cout;
using std::endl;
using std::unordered_map;
using std::string;
int main()
{
	unordered_map<string,string> u={
		{"RED","#FF0000"},
		{"GREEN","00FF00"},
		{"BLUE","0000FF"}};
	for(const auto &n:u)
	{
		cout<<"key:["<<n.first<<"]Value:["<<n.second<<"]\n";
	}

	u["BLACK"]="#000000";
	u["WHITE"]="#FFFFFF";

	cout<<"The HEX of color RED is:["<<u["RED"]<<"]\n";
	cout<<"The HEX of color BLACK is:["<<u["BLACK"]<<"]\n";

	return 0;
}

 ///
 /// @file    4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 16:17:22
 ///
 
#include <iostream>
#include<vector>
#include<string>
using std::string;
using std::cout;
using std::endl;
using std::vector;
struct poker{
	vector<string> color;
	vector<int> num;
};
int main()
{
	cout<<sizeof(struct poker)<<endl;
	return 0;
}


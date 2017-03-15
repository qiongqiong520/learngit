 ///
 /// @file    copy.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 11:36:55
 ///
 //拷贝函数
#include<algorithm>
#include<vector>
#include<iterator>
#include<numeric>
#include <iostream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::copy;

int main(void)
{
	vector<int>from_vector(10);
	iota(from_vector.begin(),from_vector.end(),0);

	vecctor<int> to_vector;
	copy(from_vector.begin(),from_vector.end(),

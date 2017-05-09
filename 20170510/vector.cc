 ///
 /// @file    vector.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 04:02:39
 ///
 
#include <iostream>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
	vector<int> vecInt;
	vecInt.push_back(1);

	cout<<vecInt.top()<<endl;
	vecInt.pop();
	return 0;
}

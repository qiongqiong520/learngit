 ///
 /// @file    for_each.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-02 20:46:28
 ///
 
#include <iostream>
#include<algorithm>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

void print(int num)
{
	cout<<num<<" ";
}

int main(void)
{
	vector<int> vecInt ={1,2,3,4,5,6};
	for_each(vecInt.begin(),vecInt.end(),print);
	cout<<endl;

	return 0;
}

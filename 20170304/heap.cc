 ///
 /// @file    heap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-04 14:30:42
 ///
#include<vector>
#include<algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::make_heap;
using std::sort_heap;
using std::vector;
int main(void)
{
	vector<int> v={3,1,4,1,5,9};

	make_heap(v.begin(),v.end());
	cout<<"heap:\t";
	for(const auto &i:v)
	{
		cout<<i<<" ";
	}
	sort_heap(v.begin(),v.end());
	cout<<"\nsorted:\t";
	for(const auto &i:v)
	{
		cout<<i<<" ";
	}
	cout<<"\n";
}

 ///
 /// @file    reserver_iterator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 10:53:49
 ///
 
#include <iostream>
#include<vector>
#include<iterator>

using std::cout;
using std::endl;
using std::vector;
using std::ostream_iterator;

int main(void)
{
	vector<int> vecInt={1,2,3,4,5,6};//创建一个空的迭代器，并附初值
	vector<int>::reverse_iterator it;
	for(it=vecInt.rbegin();it!=vecInt.rend();++it)
	{
		cout<<*it<<" ";
	}
	cout<<endl;

	ostream_iterator<int> osi(cout," ");
	copy(vecInt.rbegin(),vecInt.rend(),osi);
	cout<<endl;
	return 0;
}





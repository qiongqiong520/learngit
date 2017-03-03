 ///
 /// @file    remove.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-03 10:28:55
 ///
 
#include <iostream>
#include<algorithm>
#include<vector>
using std::cout;
using std::endl;
using std::vector;

int main(void)
{
	vector<int> vecInt={1,2,3,4,5,6,7,8,9,10};
	cout<<"vecInt's capacity="<<vecInt.capacity()<<endl;

	vecInt[3]=vecInt[5]=vecInt[9]=100;
	for(auto&elem:vecInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;

	//remove在遍历容器过程中，并没有做删除操作
	//erase-remove惯用法
	vecInt.erase(remove(vecInt.begin(),vecInt.end(),99),vecInt.end());
	for(auto&elem:vecInt)
	{
		cout<<elem<<" ";
	}
	cout<<endl;
	return 0;
}

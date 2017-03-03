///
/// @file    move_if.cc
/// @author  lemon(haohb13@gmail.com)
/// @date    2017-03-03 15:44:18
///

#include <iostream>
#include<list>
using std::cout;
using std::endl;
using std::list;

int main(void)
{
	list<int> l ={1,100,2,3,10,1,11,-1,12};
	l.remove(1);
	l.remove_if([](int n){return n>10;});//输出小于10的元素
	for(int n:l)
	{
		cout<<n<<" ";
	}
	cout<<endl;
	return 0;
}

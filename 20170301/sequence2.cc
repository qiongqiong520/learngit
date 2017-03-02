 ///
 /// @file    sequence2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-01 15:26:42
 ///
 
#include <iostream>
#include<vector>
#include<deque>
#include<list>


using std::cout;
using std::endl;
using std::vector;
using std::list;

template<typename Container>
void printContainer(Container & c)
{
	typename Container::iterator cit;
	for(cit= c.begin();cit!=c.end)
}

int main(void)
{
	vector<int> vecInt = {1,2,3,4,5};
	printContainer(vecInt);

	vecInt.pop_back();

	return 0;
}

 ///
 /// @file    insert_interator.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-02 23:08:03
 ///
 
#include <iostream>
#include<iterator>
#include<vector>
#include<list>
#include<algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::list;

template<typename Container>
void printElements(Container & c)
{
	typename Container::const_iterator cit;
	for(cit=c.begin();cit!=c.end();++cit)
	{
		cout<<*cit<<endl;
	}
	cout<<endl;
}
int main(void)
{
	vector<int>vecInt={1,2,3};

	list<int>listInt;

	copy(vecInt.begin(),vecInt.end(),std::back_insert_iterator<list<int> >(listInt));
	printElements(listInt);


	copy(vecInt.begin(),vecInt.end(),std::back_insert_iterator<list<int> >(listInt));
	printElements(listInt);

	copy(vecInt.begin(),vecInt.end(),std::front_insert_iterator<list<int> >(listInt,++listInt.begin()));
	printElements(listInt);

	return 0;
}

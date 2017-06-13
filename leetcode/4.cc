 ///
 /// @file    4.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 13:33:18
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int *ip =static_cast<int*>(malloc(sizeof(int)));
	*ip =10;
	delete ip;
	return 0;
}

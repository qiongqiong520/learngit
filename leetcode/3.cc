 ///
 /// @file    3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 13:32:42
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int *a =new int(12);
	free (a);
	return 0;
}

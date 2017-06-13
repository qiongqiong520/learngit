 ///
 /// @file    1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 13:30:07
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int *ip= new int(12);
	for(int i=0;i<12;++i){
		ip[i]=i;
	}
	delete []ip;
	return 0;
}

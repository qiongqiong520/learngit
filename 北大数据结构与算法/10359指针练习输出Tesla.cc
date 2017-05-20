 ///
 /// @file    10359指针练习输出Tesla.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:53:14
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void Print(const char* p1,const char * p2)
{
	for(;p1<p2;++p1)
		cout<<*p1;
}

int main()
{
	const char* s="Tesla123";
	Print(s,s+5);
	cout<<endl;
	Print(s,s+3);
	cout<<endl;

	return 0;
}

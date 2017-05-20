 ///
 /// @file    10358指针练习输出hello.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:52:48
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main()
{
	char s[]="Hello";
	char *p;
	for(p=s;p[0];++p)
		cout<<*p;
	return 0;
}

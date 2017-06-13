 ///
 /// @file    sizeof.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-10 13:19:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main()
{
	int intValue=1024;
	char str[]="Tencent";
	const char* ch=str;
	cout<<sizeof(intValue)<<endl;
	cout<<sizeof(str)<<endl;
	cout<<sizeof(ch)<<endl;
	return 0;
}

 ///
 /// @file    1001温度转换.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-01 16:38:22
 ///
 
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main()
{
	float C,F;
	cin>>F;
	C=(F-32)*5/9;
	printf("%.4f\n",C);
	return 0;
}

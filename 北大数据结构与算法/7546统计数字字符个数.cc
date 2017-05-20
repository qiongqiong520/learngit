 ///
 /// @file    7546统计数字字符个数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:16:21
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

char line[400];
int main()
{
	cin.getline(line,300);
	int total =0;
	for(int i=0;line[i];++i)
	{
		if(line[i]>='0'&&line[i]<='9')
			++total;
	}
	cout<<total;
	return 0;
}

 ///
 /// @file    main.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-03 22:27:24
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int func()
{
	int i,j,k=0;
	for(i =0,j=-1;j==0;i++,j++)
	{k++;
	}
	return k;
}
int main()
{
	cout<<func();
}

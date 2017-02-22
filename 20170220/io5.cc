 ///
 /// @file    io5.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 17:30:23
 ///
 
#include <iostream>
#include<fstream>
using std::cout;
using std::endl;
using std::ofstream;

int main(void)
{
	ofstream ofs("abc.txt");
	if(!ofs.good())
	{
		cout<<"ofstream open error!"<<endl;
		return -1;
	}
	String str = "that's nes";

	ofs <<str;

	ofs.close();

	return 0;
}

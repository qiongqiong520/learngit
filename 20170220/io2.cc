 ///
 /// @file    11.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 15:27:20
 ///
 
#include<string.h>//标准输入输出流
#include<fstream>//文件输入输出流
#include <iostream>
#include<limit.h>
using std::cout;
using std::endl;
using std::cin;
using std::ifstream;
using std::string;



int main(void)
{
	ifstream ifs("11.cc");//要求打开的文件
	if(!ifs.good())
	{
	cout<<"ifstream open error!"<<endl;
	return -1;
	}
	string str;

	while(getline(ifs,tr))
	{
		cout<<str<<endl;
	}
}

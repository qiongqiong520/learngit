 ///
 /// @file    SafeFile.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-07 00:04:37
 ///
#include<stdio.h>
#include <iostream>
#include<string>
using std::cout;
using std::endl;
using std::string;

class SafeFile
{
	public:
		SafeFile(FILE * fp)
			:_fp(fp)
		{
		}
		~SafeFile()
		{
			cout<<"~SafeFile()"<<endl;
			delete []
	private:
		FILE *fp;
};

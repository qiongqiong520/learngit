 ///
 /// @file    delete.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-07 23:44:13
 ///
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<memory>
#include<fstream>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::unique_ptr;
using std::ofstream;

struct Fpcloser
{
 	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout<<"fclose(fp)"<<endl;
		}
	}
};

struct OstreamCloser
{
 	void operator()(ofstream * ofs)
	{
		if(ofs)
		{
			ofs->close();
			cout<<"ofstream close()"<<endl;
		}
	}
};

int test(void)
{ //报段错误
	shared_ptr<FILE> spFile(fopen("tex.txt","rw+"),Fpcloser());
	char buff[1024];
	strcpy(buff,"hello");

	fwrite(buff,1,5,spFile.get());
	return 0;
}

int main(void)
{
	ofstream ofs("test.txt",std::ios::app);
	unique_ptr<ofstream,OstreamCloser> upOfstream(&ofs,OstreamCloser());

	ofs<<"hello"<<endl;
	return 0;
}

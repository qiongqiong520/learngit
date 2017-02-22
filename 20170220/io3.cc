 ///
 /// @file    io3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 17:16:19
 ///
 
#include <iostream>
#include<limits>
#include<fstream>
#include<string>

using std::cout;
using std::endl;
uisng std::vector;
using std::ifstream;
using std::ofstream;
using std::string;

void reserve(siez_t n)
{
	cot<<"cin's badbit = "<<cin.bad()<<endl;
	cot<<"cin's badbit = "<<cin.bad()<<endl;
	cot<<"cin's badbit = "<<cin.bad()<<endl;
	cot<<"cin's badbit = "<<cin.bad()<<endl;
}


int main(void)
{
	ifstrem ifs("io2.cc");//要求打开文件内容
	if(!ifs.good())
	{
		cout<<"ifstream open error!"<<endl;
		return -1;
	}
	ofstream ofs("io2.cc");//该文件不需要存在
	if(!ofs.good())
	{
		cout<"ofstream open error!"<<endl;
		ifs.close();//关闭文件句柄或文件指针
		return -1;
	}
	string line;
	while(getline(ifs,line)){
		ofs<<line<<endl;
	}

	return 0;
}




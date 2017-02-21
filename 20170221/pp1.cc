 ///
 /// @file    pp1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 11:11:06
 ///
#include<iostream>

//#include "iostream" //默认优先在当前目录下查找
#include<log4cpp/Category.hh>
#include<log4cpp/OstreamAppender.hh>
#include<log4cpp/BasicLayout.hh>
#include<log4cpp/Priority.hh>
using std::cout;
using std::endl;

int main(void)
{
	log4cpp::OstreamAppender * osAppender = 
		new log4cpp::OstreamAppender("osAppender",&cout);
	osAppender->setLayout(new log4cpp::BasicLayout());

	log4cpp::Category & root = log4cpp::CAtegory::getRoot();
	root.add

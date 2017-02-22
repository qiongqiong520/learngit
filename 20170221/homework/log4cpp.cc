 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 10:43:28
 ///
 
#include <iostream>
using std::cout;
using std::endl;

int main(void)
{
	log4cpp::OstreamAppender* osAppender= new
		log4cpp::OstreamAppender::getInstance();
	osAppender.get

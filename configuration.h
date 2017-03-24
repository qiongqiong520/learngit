 ///
 /// @file    configuration.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-23 22:55:31
 ///
#ifndef _CPP_PROJECT_CONFIGURATION_H_
#define _CPP_PROJECT_CONFIGURATION_H_

#include<iostream>
#include<map>
#include<stding>

using std::cout;
using std::endl;
using std::map;
using std::string;

namespace wd
{
	class MyConf
	{
		public:
		private:
			std::map<std::string,std::string> conf_;
	};

}//end of namespace we
#endif

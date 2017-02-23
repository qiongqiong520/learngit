 ///
 /// @file    testmylog.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-22 22:48:08
 ///
#include"Mylog.h"

#include <iostream>
#include<string>
#include<sstream>

using std::cout;
using std::endl;
using std::string;

int main(void)
{
#if 0
	Mylog * log = Mylog::getInstance();
	log->warn(postfix("warrn msg"));
	log->error(postfix("error msg");
	log->info(postfix("info msg"));
	log->debug(postfix("debug msg");
#endif


	logWarn(postfix("warrn msg"));
	logError(postfix("error msg");
	logInfo(postfix("info msg"));
	logDebug(postfix("debug msg");
#if 0
		cout<<_FILE__<<endl;
		cout<<__LINE__<<endl;
#endif
		return 0;
		}


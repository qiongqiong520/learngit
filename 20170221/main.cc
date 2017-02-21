 ///
 /// @file    main.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 21:56:15
 ///
 //main.cpp
#include <iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/PropertyConfigurator.hh>
using namespace std;

int main(int argc,char* argv[])
{	
	std::string initFileName = "log4cpp.properties";
	log4cpp::PropertyConfigurator::configure(initFileName);

	log4cpp::Category& root = log4cpp::Category::getRoot();

	log4cpp::Category& sub1=
		log4cpp::Category::getInstance(std::string("sub1"));

	log4cpp::Category& sub2 = log4cpp::Category::getInstance(std::string("sub1"));

	root.warn("Storm is coming");
	
	sub1.debug("recevie storm warning");
	sub1.info("closing all hatches");

	sub2.debug("hiding solar panels");
	sub2.error("Solar panels are shield");
	sub2.debug("Applying protective shield");
	sub2.warn("unfolding proteced shield");
	sub2.info("Solar pannel arwe shield");
	
	sub1.info("all hatches closed");
	
	root.info("ready for storm");
	
	log4cpp::Category::shutdown();

	return 0;
}


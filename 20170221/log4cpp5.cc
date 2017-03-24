 ///
 /// @file    log4cpp.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-21 14:56:46
 ///
 
#include <iostream>
#include<log4cpp/Category.hh>
#include<log4cpp/Propertyconfigurator.hh>

using std::cout;
using std::endl;

using namespace log4cpp;

int main(void)
{
	std::string initFileName ="log4cpp.properties";
	log4cpp::PropertyConfigurator::configure(initFileName);

	log4cpp::Category& root=log4cpp::Category::getRoot();

	log4cpp::Category& sub1=log4cpp::Category::getInstance(std::string("sub1"));

	log4cpp::Category& sub2=
		log4cpp::Category::getInstance(std::string("sub2"));

	root.warn("Strom is coming");

	sub1.debug("Received storm warning");
	sub1.info("closing storm warning");
	
	sub2.debug("Hiding solar panel");
	sub2.error("Solar panels are blocked");
	sub2.debug("Applying protective shield");
	sub2.warn("Unfolding protective shield");
	sub2.info("Solar panel are shielded");

	sub1.info("All hatches closed");
	root.info("Ready for storm");

	log4cpp::Category::shutdown();

	return 0;
}


 ///
 /// @file    composition.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-08 16:17:08
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Mouse
{
	public:
		void eat()
		{
			cout<<"Mouse::eat()"<<endl;
		}
};
class Ear
{
	public:
		void listen()
		{
			cout<<"Ear::listen()"<<endl;
		}
};
class Eye
{


 ///
 /// @file    computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 10:41:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Comouter{
	public:
		static void printTotalPrice();

		void print()
		{
			cout<<"价格:"<<this->price<<endl;
		}
	private:
		char * _totalPrice;

};


int main(void)
{

	Computer ;
	return 0;
}

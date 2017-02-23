 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-23 09:40:50
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class String{
	public:
		//默认构造函数
		String(){}
	void print()
	{
		cout<<_pstr<<endl;
	}
	private:
		char* _pstr;
};

int main(void)
{
		String s1;
		s1.print();

		cout<<"----"<<endl;

		return 0;
}

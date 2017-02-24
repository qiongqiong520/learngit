 ///
 /// @file    operator_arrow.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-24 15:19:48
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Data{
	public:
		int length()
		{
			return 5;
		}
};

class DataPtr
{
	public:
		DataPtr()
			:_p(new Data)
		{
		}
		~DataPtr()
		{
			delete _p;
		}
		Data * operator->()
		{
			return _p;
		}

	private:
		Data * _p;
};

int main(void)
{
	DataPtr dp;
	cout<<dp->length()<<endl;

	cout<<(dp.operator->())->length()<<endl;
return 0;
}


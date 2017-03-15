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
		String()
		:_pstr(new char [1])
		{
			cout<<_pstr<<endl;
		}//定义有参构造函数，默认执行无参构造函数
		String(const char *pstr)
		:_pstr(NULL)//浅拷贝
		{
			cout<<"world"<<endl;
		}
	void print()
	{
		cout<<_pstr<<endl;
	}
	private:
		char* _pstr;
};

int main(void)
{
		String s1="hello";
		//s1.print();

		cout<<"--"<<endl;
		String s2=s1;
		//s2.print();

		cout<<"----"<<endl;

		return 0;
}

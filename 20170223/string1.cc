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
		String()//浅拷贝,复地址值
		//:_pstr(pstr)
		:_pstr(new char[strlen(pstr)+1])//深拷贝
		{
			strcpy(_pstr,pstr);
		}
#if 0
		//编译器为我们自动提供的默认构造函数
	String (const String & rhs)
		:_pstr(rhs._pstr)
	{

	}
#endif 

	String (const String & rhs)
		:_pstr(new char[strlen(rhs._pstr)+1]
	{

			strcpy(_pstr,pstr);
	}
	String & operator =(const String &rhs)
	{
		if(this ==&rhs)
		{
		return *this;
		}
		delete []_pstr;
		_pstr =new char[strlen(pstr)+1];

	}
	~String()
		{
			delete [] _pstr;
		}
	void print()
	{
		cout<<_pstr<<endl;
	}
	private:
		char * _pstr;
};

int main(void)
{
		String s1;
		s1.print();
		s1.print();
		
		String s2="hello";//位于文字常量区
		s2.print();
		
		String s3 =s2;//调用复制构造函数
		s3.print();
		cout<<"----"<<endl;
		

		String s4 ="world";//调用复制构造函数
		s3.print();
		cout<<"----"<<endl;
		return 0;
}

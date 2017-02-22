 ///
 /// @file    1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 10:13:34
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class String
{
	public:
		String()
			:_pstr(new char[1])
		{
			cout<<"string()"<<endl;
		}
		String(const char* pstr)
			:_pstr(new char[strlen(pstr)+1])
		{
			strcpy(_pstr,pstr);
			cout<"string(const char* pstr)"<<endl;
		}
#if 0
		string(const String &rhs)
			:_pstr(rhs._pstr)//浅拷贝
		{
			
		}
#endif
		String(const String &rhs)
			:_pstr(new char[strlen(rhs._pstr)+1])
		{
			strcpy(_pstr,rhs._pstr);
			cout<<"Stirng (const String &rhs)"<<endl;
		}

		String & operator = (const String & rhs)
		{
			if(this == &rhs)//自复制
			{

			deletc []_pstr;//释放原对象已经申请的空间

			_pstr = new char[strlen(rhs._pstr)+1]);//再去复制
			strcpy(_pstr,rhs._pstr);
			}
			return (*this);
		}
	~String()//析构函数不满足需求，需要自定义
	{
		//析构函数只做清理工作
		delete []_pstr;
		cout<<"~String()"<<endl;
	}

	private:
		char *_pstr;
	
};//封装c下的一个指针类型


int main(void)
{
	String s1="hello";
	String s2 = "world";

	s1=s1;

	s1=s2;
	return 0;
}

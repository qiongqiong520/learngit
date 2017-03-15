#include<stdio.h>
#include<string.h>
#include<iostream>

using std::cout;
using std::endl;

class String{
	friend std::ostream & operator<<(std::ostream & os,const String & rhs);
	public:
 		String();
		String(const char* pstr);
		String(const String & rhs);
		~String();

		String & operator=(const String & rhs);
		int size() const
		{
			return strlen(_pstr);
		}

		const char* c_str() const
		{
			return _pstr;
		}
		int useCount() const
		{
 			return _pstr[size() +1];
		}

		void initRefCount()//初始化引用计数，
		{
			_pstr[size()+1]=1;
		}

		void increaseRefCount()//当有其他字符串复制该对象时，引用计数自动加1
		{
			++_pstr[size()+1];
		}

		void decreaseRefCount()//当有对象析构该str时，引用计数自动减1
		{
			--_pstr[size()+1];
		}

		char & operator[](int idx);
	private:
		char *_pstr;
};


String::String()
  	:_pstr(new char[2])//深拷贝
	 {
  		 cout<<"String()"<<endl;
		 initRefCount();
	 }
String::String(const char * pstr)
 	:_pstr(new char[strlen(pstr)+2])//深拷贝
	 {
 		 cout<<"String::String(const char * pstr)"<<endl;
		strcpy(_pstr,pstr);
		 initRefCount();
	 }
String::String(const String & rhs)
	:_pstr(rhs._pstr)
{
	increaseRefCount();
}
String & String::operator=(const String & rhs)
{
 	if(this == &rhs)
		return * this;
	decreaseRefCount();
	if(useCount()==0)
		delete []_pstr;
	_pstr =rhs._pstr;
	increaseRefCount();

	return *this;
}

String::~String()
{
  	if(--_pstr[size()+1]==0)
	{
  		delete[]_pstr;
		cout<<"~String()"<<endl;
	}
}

//下标访问运算符无法区分读操作还是写操作
char & String::operator[](int idx)
{
  	static char chnull ='\0';
	if(idx >=0&&idx<size())
	{
  		if(useCount()>1)
		{
   			decreaseRefCount();
			char *ptmp =new char[size()+2];
			strcpy(ptmp,_pstr);
			_pstr = ptmp;
			initRefCount();
		}
		return _pstr[idx];
	}
	else
		return chnull;
}
 
std::ostream & operator<<(std::ostream & os,const String & rhs)
{
	os<<rhs._pstr;
	return os;
}

int main(void)
{
   	String s1="hello world";
 	String s2 = s1;
	String s3=s2;

	cout<<"s1= "<<s1<<endl;
	cout<<"s2= "<<s2<<endl;
	cout<<"s3= "<<s3<<endl;

	printf("&s1 =%p\n",s1.c_str());
	printf("&s2 =%p\n",s2.c_str());
	printf("&s3 =%p\n",s3.c_str());

	cout<<"s1 's usecount = "<<s1.useCount()<<endl;
	cout<<"s2 's usecount = "<<s2.useCount()<<endl;
	cout<<"s3 's usecount = "<<s3.useCount()<<endl;
	cout<<endl;

	String s4 = "shenzhen";
	String s5 = s4;

	//s5=s3;

	cout<<"s4="<<s4<<endl;
	cout<<"s5= "<<s5<<endl;
	cout<<"s4'use count = "<<s4.useCount()<<endl;
	cout<<"s5'use count = "<<s5.useCount()<<endl;

	printf("&s1 =%p\n",s1.c_str());
	printf("&s2 =%p\n",s2.c_str());
	printf("&s3 =%p\n",s3.c_str());





	return 0;
}




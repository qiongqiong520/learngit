#include<stdio.h>
#include<string.h>
#include<iostream>

using std::cout;
using std::endl;

class cow_String{
 	friend std::ostream & operator<<(std::ostream & os,const cow_String & rhs);
	public:
  		cow_String();
		cow_String(const char* pstr);
		cow_String(const cow_String & rhs);
		~cow_String();

		cow_String & operator=(const cow_String & rhs);
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


cow_String::cow_String()
   	:_pstr(new char[2])//深拷贝
	 {
   		 cout<<"cow_String()"<<endl;
		 initRefCount();
	 }
cow_String::cow_String(const char * pstr)
 	:_pstr(new char[strlen(pstr)+2])//深拷贝
	 {
 		 cout<<"cow_String::cow_String(const char * pstr)"<<endl;
		strcpy(_pstr,pstr);
		 initRefCount();
	 }
cow_String::cow_String(const cow_String & rhs)
	:_pstr(rhs._pstr)
{
	increaseRefCount();
}
cow_String & cow_String::operator=(const cow_String & rhs)
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

cow_String::~cow_String()
{
  	if(--_pstr[size()+1]==0)
	{
  		delete[]_pstr;
		cout<<"~cow_String()"<<endl;
	}
}
char & cow_String::operator[](int idx)
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
 
std::ostream & operator<<(std::ostream & os,const cow_String & rhs)
{
	os<<rhs._pstr;
	return os;
}

int main(void)
{
    cow_String s1="hello world";
 	cow_String s2 = s1;
	cow_String s3=s2;

	cout<<"s1= "<<s1<<endl;
	cout<<"s2= "<<s2<<endl;

	printf("&s1 =%p\n",s1.c_str());
	printf("&s2 =%p\n",s2.c_str());

	cout<<"s1 's usecount = "<<s1.useCount()<<endl;
	cout<<"s2 's usecount = "<<s2.useCount()<<endl;
	cout<<endl;

	return 0;
}




#include<stdio.h>
#include<string.h>
#include<iostream>

using std::cout;
using std::endl;

class cow_string{
	private:
		class CharProxy
		{
			public:
				CharProxy(int idx,cow_string & str)
					:_idx(idx)
					 ,_str(str)
			{
				cout<<"CharProxy(int idx,cow_string & str)"<<endl;
			}
				CharProxy & operator=(char ch);//赋值运算符重载
			operator char()
			{
				return _str._pstr[_idx];
			}
			private:
	 			int _idx;
				cow_string & _str;
				//char * _str;
		};
		friend std::ostream & operator<<(std::ostream &os,const cow_string &rhs);
	public:
		cow_string();
		cow_string(const char* pstr);//函数重载
		cow_string(const cow_string & rhs);
		~cow_string();

		cow_string & operator=(const cow_string &rhs);//赋值运算符重载

		int size() const
		{
			return strlen(_pstr);
		}
		const char * c_str()const
		{
			return _pstr;
		}

		int useCount()const
		{
			return _pstr[size()+1];
		}
		void initRefCount()
		{
			_pstr[size()+1]=1;
		}

		void increaseRefCount()
		{
			++_pstr[size()+1];
		}
		void decreaseRefCount()
		{
			--_pstr[size()+1];
		}

		CharProxy operator[](int idx);

	private:
		char * _pstr;
};

	cow_string::cow_string()
:_pstr(new char[2])
{
 	cout<<"cow_string()"<<endl;
	initRefCount();
}

	cow_string::cow_string(const char* pstr)
:_pstr(new char[strlen(pstr)+2])
{
 	strcpy(_pstr,pstr);
	initRefCount();
}
	cow_string::cow_string(const cow_string &rhs)
:_pstr(rhs._pstr)//浅拷贝
{
	increaseRefCount();
}

cow_string & cow_string::operator=(const cow_string & rhs)//赋值运算符重载
{
 	if(this==&rhs)
		return *this;
	decreaseRefCount();
	if(useCount()==0)
		delete []_pstr;
	_pstr=rhs._pstr;
	increaseRefCount();

	return *this;
}

cow_string::~cow_string()
{
 	if(--_pstr[size()+1]==0)
	{
		delete []_pstr;
	}
	cout<<"~cow_string()"<<endl;
}
#if 0
char & cow_string::operator[](int idx)
{
	static char chnull='\0';
	if(idx>=0&&idx<size())
	{
		if(useCount()>1)
		{
			decreaseRefCount();
			char * ptmp = new char[size()+1];
			strcpy(ptmp,_pstr);
			_pstr =ptmp;
			initRefCount();
		}return _pstr[idx];
	}
	else
		return chnull;
}
#endif
cow_string::CharProxy cow_string::operator[](int idx)
{
	return CharProxy(idx,*this);
}

#if 0
char & cow_string::operator[](int idx)
{
	static char chnull ='\0';
	if(idx>=0&&idx<size())
	{
		if(useCount()>1)
		{
			deacreaseRefCount();
			char *ptmp=new char[size()+2];
			strcpy(ptmp,_pstr);
			_pstr=ptmp;
			initRefCount();//初始化引用计数
		}
		return _pstr[idx];
	}
	else
		return chnull;
}
#endif


cow_string::CharProxy & cow_string::CharProxy::operator=(char ch)
{
 	if(_idx>=0&&_idx<_str.size())
	{
 		if(_str.useCount()>1)
		{
 			_str.decreaseRefCount();
			char * ptmp=new char[_str.size()+2];
			strcpy(ptmp,_str._pstr);
			_str._pstr =ptmp ;
			_str.initRefCount();
		}
		_str._pstr[_idx]=ch;
	}else
		cout<<"栈为空"<<endl;
	return *this;
}
std::ostream & operator <<(std::ostream & os,const cow_string & rhs)
{
 	os<<rhs._pstr;
	return os;
}

int main(void)
{
 	cow_string s1="hello,world";
	cow_string s2 =s1;
	cow_string s3=s2;

	cout<<"s1= "<<s1<<endl;
	cout<<"s2= "<<s2<<endl;
	cout<<"s3= "<<s3<<endl;
	printf("&s1=%p\n",s1.c_str());
	printf("&s2=%p\n",s2.c_str());
	printf("&s3=%p\n",s3.c_str());
	cout<<"s1's use count = "<<s1.useCount()<<endl;
	cout<<"s2's use count = "<<s2.useCount()<<endl;
	cout<<"s3's use count = "<<s3.useCount()<<endl;
	cout<<endl;

	cow_string s4="shenzhen";
	cow_string s5=s4;
	s5=s3;

	cout<<"s4 ="<<s4<<endl;
	cout<<"s5= "<<s5<<endl;
	cout<<"s4's use count = "<<s4.useCount()<<endl;
	cout<<"s5's use count = "<<s5.useCount()<<endl;
	cout<<"s1's ussecount= "<<s1.useCount()<<endl;
	printf("&s4=%p\n",s4.c_str());
	printf("&s4=%p\n",s5.c_str());

	cout<<endl<<"进行读操作"<<endl;
	s1[0]='X';
	cout<<"s1 = "<<s1<<endl;
	cout<<"s2= "<<s2<<endl;
	cout<<"s1's use count = "<<s1.useCount()<<endl;
	cout<<"s2's use count = "<<s2.useCount()<<endl;
	cout<<"s3's use count = "<<s3.useCount()<<endl;
	cout<<"s5's ussecount= "<<s5.useCount()<<endl;
	
	s4[0]='Y';
	cout<<"s4= "<<s4<<endl;
	cout<<"s4's use count = "<<s4.useCount()<<endl;
	printf("&s4 =%p\n",s4.c_str());

	cout<<endl<<"执行写操作"<<endl;
	cout<<s2[0]<<endl;
	
	cout<<"s2's use count = "<<s2.useCount()<<endl;
	cout<<"s3's use count = "<<s3.useCount()<<endl;
	cout<<"s5's ussecount= "<<s5.useCount()<<endl;
	printf("&s2=%p\n",s2.c_str());
	printf("&s3=%p\n",s3.c_str());

	return 0;
}


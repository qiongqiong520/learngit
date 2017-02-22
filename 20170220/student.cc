 ///
 /// @file    student.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-02-20 14:41:11
 ///
#include<string.h>
#include<stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class Student{
	public:
		Student (int no,char * name)
			:_no(no)
			 ,_name(new char[strlen(name)+1])
	{
		strcpy(_name,name);
	}
		void print()
		{
			cout<<"学号：“<<_no<<endl;
			cout<<"姓名："<<_name<<endl;
		}
		void *operator new(size_t size)
		{
			cout<<"void * operator new(size_t)<<endl;
			void *p=malloc(size);//只开辟空间不负责初始化
			return p;
		}
		void operator new(Size_t size)
		{
			delete []_
	private:
		int _no;
		char _name;
};

int main(void)
{
	Student  *s1 =new Student(100,"MIke");
	s1->print();

	delete s1;

	return 0;
}



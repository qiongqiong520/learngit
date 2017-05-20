 ///
 /// @file    10367指针练习swap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:55:37
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void SwapMemory(void * m1,void * m2,int size)
{
	char * p1=(char*)m1;
	char * p2=(char *)m2;
	for(int i=0;i<size;++i){
		char tmp=p1[i];
		p1[i]=p2[i];
		p2[i]=tmp;
	}
}

void PrintIntArray(int * a,int n)
{
	for(int i=0;i<n;++i)
		cout<<a[i]<<",";
	cout<<endl;
}

int main()
{
	int a[5]={1,2,3,4,5};
	int b[5]={10,20,30,40,50};
	SwapMemory(a,b,5*sizeof(int));
	PrintIntArray(a,5);
	PrintIntArray(b,5);
	char s1[]="12345";
	char s2[]="abcde";
	SwapMemory(s1,s2,5);
	cout<<s1<<endl;
	cout<<s2<<endl;
	return 0;
}

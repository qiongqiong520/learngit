 ///
 /// @file    10360指针练习Memory.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:53:52
 ///
 
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void Memory(char * src,char * dest,int n)
{
	for(int i=0;i<n;i++)
		dest[i]=src[i];
}
int Strlen(char *s)
{
	int i;
	for(i =0;s[i];++i);
	return i;
}
int main()
{
	int a;
	char s1[30];
	char s2[30];
	int t;
	cin>>t;
	for(int i=0;i<t;++i){
		cin>>a;
		int b=99999999;
		Memory((char *)&a,(char*)&b,sizeof(int));
		cout<<b<<endl;
	}
	for(int i=0;i<t;++i){
		cin>>s1;
		Memory(s1,s2,Strlen(s1)+1);
		cout<<s2<<endl;
	}
	return 0;
}

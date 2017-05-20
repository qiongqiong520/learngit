 ///
 /// @file    7599石头剪子布.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:16:59
 ///
 
#include <iostream>
#include<cstdio>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

char s1[20],s2[20];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>s1>>s2;
		if(strcmp(s1,"Rock")==0){
			if(s2[0]=='S')
				cout<<"Player1"<<endl;
			else if (s2[0]=='P')
				cout<<"Player2"<<endl;
			else
				cout<<"Tie"<<endl;
		}
		else if(strcmp(s1,"Paper")==0){
			if(s2[0]=='S')
				cout<<"Player2"<<endl;
			else
				cout<<"Tie"<<endl;
		}
		if(strcmp(s1,"Scissors")==0){
			if(s2[0]=='S')
				cout<<"Tie"<<endl;
			else if(s2[0]=='P')
				cout<<"Player1"<<endl;
			else
				cout<<"Player2"<<endl;
		}
	}
	return 0;
}

 ///
 /// @file    1040到底有几个PAT.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 20:56:27
 ///
 
#include <iostream>
#include<string>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main()
{
	string s;
	while(cin>>s){
		int length=s.size();
		int uglynum=0;
		for(auto a:s){
	 		if(a=='A'&&a++=='A')uglynum++;
			else if(a=='?'&&a++=='?')uglynum++;
			else if(a=='B'&&a++=='B')uglynum++;
		}
		cout<<uglynum<<endl;
	}
	return 0;
}

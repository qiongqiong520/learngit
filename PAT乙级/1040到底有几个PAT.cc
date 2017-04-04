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
		long long p=0,pa=0,pat=0;
		for(auto a:s){
	 		if(a=='P')p++;
			else if(a=='A')pa+=p;
			else pat+=pa;
		}
		pat%=1000000007;
		cout<<pat<<endl;
	}
	return 0;
}

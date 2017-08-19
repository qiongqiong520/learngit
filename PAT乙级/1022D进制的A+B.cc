 ///
 /// @file    D进制的A+B.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 15:45:41
 ///
 
#include <iostream>
#include<string>
#include<algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc,char* argv[])
{
	int a,b,d;
	while(cin>>a>>b>>d){
		string ret;
		int c=a+b;
		while(c>=d){
			ret.push_back(c%d+'0');
			c/=d;
		}
		ret.push_back(c+'0');
		reverse(ret.begin(),ret.end());
		cout<<ret<<endl;
	}
	return 0;
}

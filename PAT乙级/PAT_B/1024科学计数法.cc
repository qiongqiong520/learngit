 ///
 /// @file    科学计数法.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 15:57:09
 ///
#include<string>
#include <iostream>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int strtoint(string s)
{
	int ret=0;
	for(int i=0;i<s.size();i++)
	{
		ret=ret*10+s[i]-'0';
	}
	return ret;
}

int main(int argc,char* argv[])
{
	string number;
	cin>>number;
	if(number[0]=='-')cout<<'-';
	string s1,s2;
	int i=3;
	while(number[i]!='E')i++;
	s1.push_back(number[1]);
	s1=s1+number.substr(3,i-3);
	int ispos=false;
	if(number[i+1] =='+')ispos=true;
	s2=number.substr(i+2,number.size()-i-2);
	int diff=strtoint(s2);
	if(ispos){
	 	if(diff+1<s1.size())
			s1.insert(diff+1,".");
		if(diff+1>s1.size()){
	 		string st;
			for(int i=0;i<diff-s1.size()+1;i++)
				st.push_back('0');
			s1=s1+st;
		}
	}
	else{
	 	string st;
		for(int i=0;i<diff;i++)
			st.push_back('0');
		s1=st+s1;
		s1.insert(1,".");
		}
		cout<<s1<<endl;
 		return 0;
}

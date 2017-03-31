 ///
 /// @file    1017A除以B-2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 10:36:11
 ///
#include<iostream>
#include<string>

using namespace std;

int main(int argc,char* argv[])
{
	string num;
	int div=0;
	while(cin>>num>>div){
		string Q;
		int R;
		int temp=num[0]-'0';
		int i=0;
		while(i<num.size()){
			if(i==num.size()){
				R=temp;
				break;
			}
			if(temp<div&&i<num.size()-1)
				temp=temp*10+num[++i]-'0';

			Q.push_back(temp/div+'0');
			temp %=div;
		}
		int k=0;
		while(Q[k]=='0')k++;
		if(Q.substr(k,Q.size()).size()==0)
			cout<<0;
		cout<<Q.substr(k,Q.size()-k)<<" "<<R<<endl;
	}
	return 0;
}

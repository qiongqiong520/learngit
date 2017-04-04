 ///
 /// @file    1039到底买不买.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 20:46:44
 ///
 
#include <iostream>
#include<string>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(){
	string s,b;
	while(cin>>s>>b)
	{
		int hs[256]={0};
		int hb[256]={0};
		for(int i=0;i<s.size();i++)hs[s[i]]++;
		for(int i=0;i<b.size();i++) hb[b[i]]++;
		int Cluck =0,Csur=0;
		bool candy =true;
		for(int i=0;i<256;i++){
			if(hs[i]>hb[i])Csur+=hs[i]-hb[i];
			if(hs[i]<hb[i]){Cluck+=hb[i]-hs[i];candy =false;}
		}
		if(candy)cout<<"Yes"<<" "<<Csur<<endl;
		else cout<<"No"<<" "<<Cluck<<endl;
	}
	return 0;
}



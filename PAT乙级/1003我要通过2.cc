 ///
 /// @file    1003我要通过2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 15:21:16
 ///
 
#include <iostream>
#include<vector>
#include<string>
using std::string;
using std::cin;
using std::vector;
using std::cout;
using std::endl;

bool judge(string s)
{
 	int n=s.size();
	int pindex =0,tindex=0;
	int pcount=-1,tcount=-1;

	for(int i=0;i<n;i++){
		if(s[i]!='P'&&s[i]!='A'&&s[i]!='T')
			return false;
		else if(s[i]=='P'){pindex=i;pcount++;}
		else if(s[i]=='T'){tcount=i;tcount++;}

	}
	if(pindex==-1||tindex==-1||pcount>1||tcount>1||pindex>tindex)
		return false;
	int ppre =pindex;
	int ptot=tindex-pindex-1;
	int tnext=n-tindex-1;
	if(ptot>=1&&ppre*ptot ==tnext) 
		return true;
	else  
		return false;
}
int main()
{
	int n;
	while(cin>>n){
		vector<string> str;
		string s;
		for(int i=0;i<n;i++){
			cin>>s;
			str.push_back(s);
		}

		for(int i=0;i<str.size();i++){
			if(judge(str[i]))
				cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}

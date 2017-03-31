 ///
 /// @file    1003我要通过.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 14:46:26
 ///
 
#include <iostream>
#include<vector>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;


bool judge(string s){
	int  n=s.size();
	int pindex =-1,tindex=-1;
	int pcount =0,tcount =0;
	for(int i=0;i<n;i++){
		if( s[i]!='P'&&s[i]!='A'&&s[i]!='T')
			return false;
		else if(s[i]=='P'){pindex=i;pcount++;}
		else if(s[i]=='T'){tindex =i;tcount++;}
	}
	if(pindex ==-1||tindex ==-1||pcount>1||tcount>1||pindex>tindex)
		return false;
	int ppre =pindex;
	int port =tindex-pindex-1;
	int tnext =n-tindex-1;
	if(port>=1&&ppre*port ==tnext)return true;
	else return false;
}

int main(int argc,char* argv[])
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
				else
					cout<<"NO"<<endl;
		}
		}
	//system("pause");
	return 0;
}

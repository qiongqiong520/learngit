 ///
 /// @file    1019数字黑洞.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 14:46:45
 ///
 
#include <iostream>
#include<algorithm>
#include<string>
using std::cin;
using std::string;
using std::cout;
using std::endl;

bool cmp(const int a,const int b){
	return a>b;
}

int tonum(string s){
	int ret =0;
	for(int i=0;i<s.size();i++){
		ret=ret*10+s[i]-'0';
	}
	return ret;
}

string tostr(int a){
	string ret;
	for(int i=0;i<4;i++){
		if(a>0){
			ret.push_back(a%10+'0');
			a/=10;
		}
		else ret.push_back('0');
	};
	reverse(ret.begin(),ret.end());
	return ret;
}

int main(int argc,char* argv[]){
	int n;
	while(cin>>n){
		int n1,n2,sub=0;
		string num1,num2;
		num1=tostr(n);
		num2=num1;
		while(sub!=6174){
			sort(num1.begin(),num1.end());
			sort(num2.begin(),num2.end(),cmp);
			if(num1==num2){
				cout<<num1<<' '<<'-'<<' '<<num2<<' '<<'='<<' '
					<<"0000"<<endl;
				break;
			}
			n1=tonum(num1);
			n2=tonum(num2);
			sub=n2-n1;
			string temp=num1;
			num1=tostr(sub);
			cout<<num2<<' '<<'-'<<' '<<temp<<' '<<'='<<' '<<num1<<endl;
			num2=num1;
		}
	}
	return 0;
}


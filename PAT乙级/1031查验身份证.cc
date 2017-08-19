 ///
 /// @file    查验身份证.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 14:35:15
 ///
 
#include <iostream>
#include<string>
using std::cin;
using std::string;
using std::cout;
using std::endl;

 	int weight[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char M[]={'1','0','X','9','8','7','6','5','4','3','2'};
	bool check(string s){
		int sum=0;
		for(int i=0;i<17;i++){
			sum+=(s[i]-'0')*weight[i];
		}
		sum%=11;
		if(s[17]==M[sum])return true;
		else return false;
	}
int main(int argc,char* argv[])
{
 	int n;
	while(cin>>n){
 		bool pass =true;
		for(int i=0;i<n;i++){
	 		string str;
			cin>>str;
			if(!check(str)){
	 			cout<<str<<endl;
				pass=false;
			}
		}
		if(pass)cout<<"All passed"<<endl;
	}
	return 0;
}

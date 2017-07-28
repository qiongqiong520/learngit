 ///
 /// @file    B1048数字加密.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-15 19:53:37
 ///
 
#include <iostream>
#include<string>
#include<stack>
using namespace std;
int main(int argc,char* argv[])
{
 	string sA,sB;
	stack<char> sta;
	cin>>sA>>sB;
	if(sA.size()>sB.size()){
 		int diff=sA.size()-sB.size();
		while(diff--)sA.insert(0,"0");
	}
 		if(sA.size()<sB.size()){
 			int diff =sB.size()-sA.size();
			while(diff--)sA.insert(0,"0");
		}
		for(int i=sB.size()-1,k=1;i>=0;i--,k++){
 			if(k%2==0){
	 			if(sB[i]-sA[i]>=0)
					sta.push(sB[i]-sA[i]+'0');
				else
				sta.push(sB[i]-sA[i]+10+'0');
			}
			else{
			int sum=sA[i]+sB[i]-'0'-'0';
			sum%=13;
			if(sum<10)
				sta.push(sum+'0');
			else{
				if(sum==10)sta.push('J');
				if(sum==11)sta.push('Q');
				if(sum==12)sta.push('K');
				}
		}
		}
			while(!sta.empty()){
			cout<<sta.top();sta.pop();
			}
			cout<<endl;
			return 0;
}

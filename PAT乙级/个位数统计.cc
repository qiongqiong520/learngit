 ///
 /// @file    个位数统计.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 15:25:22
 ///
 
#include <iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc,char* argv[])
{
	string num;
	while(cin>>num){
		int amount[10]={0};
		int i=0;
		while(num[i]=='0')i++;
		num=num.substr(i,num.size()-i);
		for(int i=0;i<num.size();i++){
			amount[num[i]-'0']++;
		}
		for(int i=0;i<10;i++){
			if(amount[i]>0)
				cout<<i<<':'<<amount[i]<<endl;
		}
	}
	return 0;
}

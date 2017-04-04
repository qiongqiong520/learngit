 ///
 /// @file   1034 有理数四则运算.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 15:36:20
 ///
 
#include <iostream>
#include<String>
using std::cin;
using std::string;
using std::cout;
using std::endl;

string trans(string num,bool ispos){
	string ret;
	int i=0;
	if(!ispos){
		i++;
		ret.push_back('(');}
	int first =num[i]-'0';
	int last =num[i+2]-'0';
	int front =0;
	if(first>last){
	front=first/last;
	first %=last;
	}
	if(front)ret.push_back(front+'0');
	if(first)
	{
	 	ret.push_back(first+'0');
		ret.push_back('/');
		ret.push_back(last+'0');
		}
		else ret.push_back(last+'0');
		if(!ispos)ret.push_back(')');
		return ret;
}
string plusma(string num1,string num2,bool pos1,bool pos2,bool isplus =true)
{
 		if(!isplus)pos2=!pos2;
		int num1up,num2up,num1d,num2d;
		if(pos1){
			num1up=num1[0]-'0';
			num1d =num1[2]-'0';
		}
		else{
			num1up=0-num1[0]-'0';
			num1d = num1[2]-'0';
		}
		if(pos2){
	 		num2up= num2[0]-'0';
			num2d = num2[2]-'0';
		}
		else{
			num2up=0-num2[0]-'0';
			num2d = num2[2]-'0';
		}
		int up =num2d*num1up+num1d*num2up;
		int down =num2d*num1d;
		string ret;
		if(up<0){
			ret.push_back('-');
			up =0-up;
		}
}

int main(int argc,char* argv[])
{
	string num1,num2;
	while(cin>>num1>>num2){
		bool ispos1 =true,ispos2 = true;
		if(num1[0]=='-')ispos1=false;
		if(num2[0]=='-')ispos2=false;

		num1 = trans(num1,ispos1);
		num2 = trans(num2,ispos2);
        cout<<num1<<" "<<"+"<<num2<<" "<<"="<<" "<<endl;
		return 0;
	}
}



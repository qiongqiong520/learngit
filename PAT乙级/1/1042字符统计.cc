 ///
 /// @file    1042字符统计.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-04 23:14:49
 ///
#include<string>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;
int main(int argc,char* argv[])
{
	string s;
	getline(cin,s);
	int h[256]={0};
	for(int i=0;i<s.size();i++)h[s[i]]++;
	for(int i='A';i<='Z';i++)h[i+32]+=h[i];
	int max=-1,index=0;
	for(int i='a';i<='z';i++){
		if(max<h[i]){
			max=h[i];
			index=i;
		}
		if(max==h[i])index=index<i?index:i;
	}
	char ret=index;
	printf("%c %d\n",ret,max);
	return 0;
}

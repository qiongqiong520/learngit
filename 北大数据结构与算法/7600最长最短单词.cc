 ///
 /// @file    7600最长最短单词.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-20 16:17:13
 ///
 
#include <iostream>
#include<cstdio>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;
char line[30000];
bool IsLetter(char c)
{
	return (c>='a'&&c<='z')||(c>='A'&&c<='Z');
}
int main()
{
	cin.getline(line,29000);

	int longStart,shortStart;
	int maxLen=0,minLen =1<<30;
	int lastWordStart;
	
	bool wordMeet =false;
	int len=strlen(line);
	for(int i=0;i<=len;++i){
		if(IsLetter(line[i])){
			if(!wordMeet){
				wordMeet=true;
				lastWordStart=i;
			}
		}
		else{
			if(wordMeet){
				wordMeet =false;
				int wordLen =i-lastWordStart;
				if(wordLen>maxLen){
					maxLen =wordLen;
					longStart=lastWordStart;
				}
				if(wordLen<minLen){
					minLen=wordLen;
					shortStart =lastWordStart;
				}
			}
		}
	}
	for(int i=longStart;IsLetter(line[i]);++i)
			cout<<line[i];
	cout<<endl;
	for(int i=shortStart;IsLetter(line[i]);++i)
			cout<<line[i];
	return 0;
}

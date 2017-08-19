 ///
 /// @file    B1002写出这个数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-29 23:05:59
 ///
#include<cstdio>
#include<cstring>
int main(){
	char str[110];
	gets(str);
	int len=strlen(str);
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=str[i]-'0';
	}
	int num=0,ans[10];
	while(sum!=

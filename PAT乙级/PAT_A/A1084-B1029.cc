 ///
 /// @file    A1084-B1029.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-11 13:05:43
 ///
 
#include <cstdio>
#include<cstring>
using namespace std;

int main(){
	char str1[100],str2[100];
	bool HashTable[128]={false};
	gets(str1);
	gets(str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for(int i=0;i<len1;i++){
		int j;
		char c1,c2;
		for(j=0;j<len2;j++){
			c1=str1[i];
			c2 = str2[j];
			if(c1>='a'&&c1<='z')c1-=32;
			if(c2>'a'&&c2<='z')c2-=32;
			if(c1== c2)break;//如果c1在第二个字符串中出现，则跳出
		}
		if(j==len2&&HashTable[c1]==false){
			printf("%c",c1);//在第二个字符串中为出现c1，且c1未被输出过
			HashTable[c1]=true;
		}
	}
	return 0;
}

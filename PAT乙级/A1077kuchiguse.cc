 ///
 /// @file    A1077kuchiguse.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-12 20:10:08
 ///
#include<cstdio>
#include<cstring>
int n,minLen=256,ans=0;//至多100个字符串，每个字符串至多256符
char s[100][256];

int main(){
	scanf("%d",&n);//n是字符串个数
	getchar();//接受换行符
	for(int i=0;i<n;i++){
		gets(s[i]);
		int len=strlen(s[i]);
		if(len<minLen)minLen=len;//取最小长度
		for(int j=0;j<len/2;j++){//反转字符串s[i].转化为公共长度
			char temp=s[i][j];//交换str[i]与strlen[len-i】
			s[i][j]=s[i][len-j-1];
			s[i][len-j-1]=temp;
		}
	}
	for(int i=0;i<minLen;i++){
		char c=s[0][i];
		bool same=true;
		for(int j=1;j<n;j++){
			if(c!=s[j][i]){
				same=false;
				break;
			}
		}
		if(same)ans++;
		else break;
	}
	if(ans){
		for(int i=ans-1;i>=0;i--){
			printf("%c",s[0][i]);
		}
	}else{
		printf("nai");
	}
	return 0;
}

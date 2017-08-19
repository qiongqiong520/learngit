 ///
 /// @file    A1005spell-it-right.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-08 13:37:31
 ///
#include<cstdio>
#include<cstring>
char num[10][10]={//数字与单词的对应
	"zero","one","two","three","four","five","six","seven","eight","nine"};
char s[111];//初始化字符串
int digit[10];
int main(){
	gets(s);
	int len=strlen(s);
	int sum=0,numLen=0;//sum为sd数位之和,numLen计量sum大长度
	for(int i=0;i<len;i++){
		sum+=(s[i]-'0');//累加s的数位，得到sum
	}
	if(sum==0){//如果sum位0，特判输出num[0]
		printf("%s",num[0]);
	}else{
	 	//如果sum不为零
		while(sum!=0){//将sum存放到digit数组中
	 		digit[numLen++]=sum%10;
			sum/=10;
		}
		for(int i=numLen-1;i>=0;i--){//从高位到地位输出digit数组
			printf("%s",num[digit[i]]);
			if(i!=0)printf(" ");//最后一个单词不输出空格
		}
	}
	return 0;
}

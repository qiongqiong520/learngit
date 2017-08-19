 ///
 /// @file    B1048数字加密.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-08 13:14:52
 ///
#include<cstdio>
#include<cstring>
const int maxn=110;
char A[maxn],B[maxn],ans[maxn]={0};
void reverse(char s[]){//反转字符串
	int len=strlen(s);
	for(int i=0;i<len/2;i++){
		int temp=s[i];//交换书[i]和s[len-1-i]
		s[i]=s[len-1-i];
		s[len-1-i]=temp;
	}
}
int main(){
	scanf("%s %s",A,B);//整数A和B
	reverse(A);//将A和B反转
	reverse(B);
	int lenA=strlen(A);
	int lenB=strlen(B);
	int len =lenA>lenB?lenA:lenB;//a和b的较大长度
	for(int i=0;i<len;i++){
		//从低位开始
		int numA=i<lenA?A[i]-'0':0;//numA对应A[i]
		int numB=i<lenB?B[i]-'0':0;//numB对应Bi
		if(i%2==0){//当前位i是偶数
			int temp=(numA+numB)%13;//和再模上13
			if(temp==10)ans[i]='J';//特判10，11，12
			else if(temp==11)ans[i]='Q';
			else if(temp==12)ans[i]='K';
			else ans[i]=temp+'0';//0~9
		}else{
			//当前位i是奇数
			int temp=numB-numA;//差
			if(temp<0)temp+=10;//如果小于0，则加上10
			ans[i]=temp+'0';//副对应字符
		}
	}
	reverse(ans);//反转结果字符串
	puts(ans);//输出结果
	return 0;
}
	

 ///
 /// @file    A1093.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-09 21:38:39
 ///
#include<cstring>
#include<cstdio>
#include <iostream>
const int MAXN=100010;
const int MOD=1000000007;
char str[MAXN];//字符串
int leftNumP[MAXN]={0};

using std::cout;
using std::endl;
int main(int argc,char* argv[]){
	gets(str);//读入字符串
	int len=strlen(str);//长度
	for(int i=0;i<len;i++){//从左侧到右遍历字符串
		if(i>0){//如果不是0号位
			leftNumP[i]=leftNumP[i-1];//继承上一位等结果
		}
		if(str[i]=='P'){//当前位是P
			leftNumP[i]++;//令leftNumP[i]加1
			}
	}
	int ans =0,rightNumT=0;//右边T的个数加1
	for(int i=len-i;i>=0;i--){//从右往左遍历字符串
		if(str[i]=='T'){//当前位置是T
			rightNumT++;//右边T的个数加1
		}else if(str[i]=='A'){//当前位置是A
			ans=(ans+leftNumP[i]*rightNumT)%MOD;//累计乘积
		}
	}
	printf("%d\n",ans);
	return 0;
}

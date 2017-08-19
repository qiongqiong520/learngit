 ///
 /// @file    B1024-A1073.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-08 12:39:33
 ///
#include<cstdio>
#include<cstring>
int main(){

	char str[10010];
	 gets(str);
	 int len=strlen(str);
	 if(str[0]=='-')printf("-");//如果负数，输出负号
	 int pos=0;//pos存放字符串中E的位置
	 while(str[pos]!='E'){
		 pos++;
	 }
	 int exp=0;//exp存放指数
	 for(int i=pos+2;i<len;i++){
		 exp=exp*10+(str[i]-'0');
	 }
	 if(exp==0){//特判指数为0的情况
		 for(int i=1;i<pos;i++){
			 printf("%c",str[i]);
		 }
	 }
	 if(str[pos+1]=='-'){//如果指数为复数
		 printf("0.");
		 for(int i=0;i<exp-1;i++){//输出(exp-1)个0
			 printf("0");
		 }
		 printf("%c",str[1]);//输出除了小数点一起的数字
		 for(int i=3;i<pos;i++){
			 printf("%c",str[i]);
		 }
	 }
		 else{//如果指数为正
			 for(int i=1;i<pos;i++){//输出小数点移动之后的指数
				 if(str[i]=='.')continue;//略过原小数点
				 printf("%c",str[i]);//输出当前小数位
				 if(i==exp+2&&pos-3!=exp){//小数点加在位置exp+2之上
		 			 //原小数点和E之间的数字个数为pos-3不能等于小数点右移位数
					 printf(".");
				 }
			 }
			 //如果指数exp较大，输出多余的0
			 for(int i=0;i<exp-(pos-3);i++){
				 printf("0");
			 }
		 }
		 return 0;
}
		

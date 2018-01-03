 ///
 /// @file    B1014-A1061福尔摩斯约会.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-06 13:32:25
 ///
 
#include<cstdio>
#include<cstring>
int main(){
	char week[7][5]={
		"MOM","TUE","WED","THU","FRI","SAT","SUN"};
	char str1[70],str2[70],str3[70],str4[70];
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	int len1=strlen(str1);
	int len2=strlen(str2);
	int len3=strlen(str3);
	int len4=strlen(str4);
	int i;
	//寻找str1和str2中第一对相同位置的A～G的大些字母
	for(int i=0;i<len1&&i<len2;i++){
		if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G'){
			printf("%s ",week[str1[i]-'A']);//输出对应是星期几
			break;
		}
	}
	//在上面基础上，往后寻找相同位置的0-9或A~N字符
	for(i++;i<len1&&i<len2;i++){
		if(str1[i]==str2[i]){
			if(str1[i]>='0'&&str1[i]<='9'){
				printf("%02d:",str1[i]-'0');//输出0~9
				break;
			}else if(str1[i]>='A'&&str1[i]<='N'){
		printf("%02d:",str1[i]-'A'+10);//输出10-23	
		break;
			}
		}
	}
	//寻找str3和str4中第一对相对位置的a~Z或啊～zd的英文字母
	for(i=0;i<len3&&i<len4;i++){
		if(str3[i]==str4[i])
			if(str3[i]==str4[i]){
				if((str3[i]>='A'&&str3[i]<='Z')||(str3[i]>='a'&&str3[i]<='z')){
					printf("%02d",i);//输出当前位置
					break;
				}
			}
		}
	return 0;
}

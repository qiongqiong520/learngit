 ///
 /// @file    1014福尔摩斯约会.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 17:37:28
 ///
 
#include <iostream>
#include<string>
#include<iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
	string s1,s2,s3,s4;
	char *day[]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	while(cin>>s1>>s2>>s3>>s4){
		int  i=0;
		for(;i<s1.size()&&i<s2.size();i++){
			if(s1[i]==s2[i]&&s1[i]>='A'&&s1[i]<='G'){
				cout<<day[(int)(s1[i]-'A')]<<" ";
				break;
			}
		}
		for(int j=i+1;j<s1.size()&&j<s2.size();j++){
			if(s1[j]==s2[j]&&(s1[j]>='A'&&s1[j]<='N'||s1[j]>='0'&&s1[j] <='9')){//&&操作优先级高于||优先级
				if(s1[j]>='A')
					cout<<(int)(s1[j]-'A'+10)<<":";
				else
					cout<<'0'<<(int)(s1[j]-'0')<<":";
				break;
			}
		}
		for(int i=0;i<s3.size()&&i<s4.size();i++){
		 	if(s3[i]==s4[i]&&((s3[i]>='A'&&s3[i]<='Z')
 						|| (s3[i]>='a'&&s3[i]<='z'))){
				cout<<i/10 << i%10 <<endl;
				break;
			}
		}
	}
	return 0;
}

	

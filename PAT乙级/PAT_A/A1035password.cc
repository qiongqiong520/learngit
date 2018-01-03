 ///
 /// @file    A1035password.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-12 19:42:45
 ///
#include<cstdio>
#include<string>
struct node{
	char name[20],password[20];
	bool ischange;//ischange==true 表示password一修改
}T[1005];

//crypt 函数判断t的password是否需要修改，若需要，则对其进习惯并令计数器cnt加1
void crypt(node& t,int& cnt){//参数使用引用了应用。可以对传入参数进行修改
	int len=strlen(t.password);
	for(int i=0;i<len;i++){//枚举password对每一位
		if(t.password[i]=='1'){//若1，则修改为@，并标记修改
			t.password[i]='@';
			t.ischange=true;
		}else if(t.password[i]=='0'){//若为0，则修改为@。并标记修改
			t.password[i]='%'; 
			t.ischange=true;
		}else if(t.password[i]=='l'){//若为了，则修改为L，并标记为一修改
			t.password[i]='L';
			t.ischange=true;
		}else if(t.password[i]=='O'){//若为‘0’，则修改为‘0’，并标记修改
			t.password[i]='o';
			t.ischange=true;
		}
	}
	if(t.ischange){//如果tpassword以修改，则令计数器cnt加1
		cnt++;
	}
}
int main(){
 	int  n,cnt=0;//cnt记录需要修改对password个数
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		 scanf("%s %s",T[i].name,T[i].password);
		T[i].ischange=false;//初始化为所有密码修改
	}
	for(int i=0;i<n;i++){
		crypt(T[i],cnt);
	}
	if(cnt==0){//没有修改判断是否需要修改
	 	 if(n==1){
	 		printf("There is %d account and no account is modified",n);
		}else{//注意修改account对但复数形式使用
				printf("There  are %d accounts and no account is modified",n);
	 			}
	}else {
	 	//有password对需要修改
		for(int i=0;i<n;i++){
	 		//如果T[i]的password需要修改,则输出name和password
			if(T[i].ischange){
				printf("%s %s\n",T[i].name,T[i].password);
			}
		}
	}
	return 0;
}
				

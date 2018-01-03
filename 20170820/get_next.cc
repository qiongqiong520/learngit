 ///
 /// @file    get_next.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-08-20 23:03:18
 ///
 void get_next(char T[],int next[]){
	 i=1;
	 next[1]=0;
	 j=0;
	 while(i<=T[0]){//T[0]用于保存字符串的长度
		 if(j==0||T[i]==T[j]){
			 ++i;++j;next[i]=j;}
		 else 
			 j=next[j];
	 }//while
 }

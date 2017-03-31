 ///
 /// @file    1006换个格式输出整数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 16:08:52
 ///
 
#include <iostream>
#include<stack>
using namespace std;

int main(int argc,char* argv[])
{
	int num;
	char output[]={'1','2','3','4','5','6','7','8','9','s','b'};
	while(cin>>num)
	{
		int i=0;
		int ret[3];
		while(num>0){
			ret[i++]=num%10;
			num /=10;
		}
		stack<char> s;
		if(i>=1)for(int k=ret[0]-1;k>=0;k--) s.push(output[k]);
		if(i>=2)for(int k=0;k<ret[1];k++)s.push(output[9]);
		if(i>=3)for(int k=0;k<ret[2];k++)s.push(output[10]);
		while(!s.empty()){
			printf("%c",s.top());
			s.pop();
		}
		printf("\n");
	}
	return 0;
}

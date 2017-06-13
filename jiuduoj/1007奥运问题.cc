 ///
 /// @file    1007奥运问题.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-18 22:40:49
 ///
 
#include <iostream>
#include<math.h>
using std::cin;
using std::cout;
using std::endl;

long long int cnt;
long long int num;

void hanoi(int n,char a,char b,char c){
	if(n==1){
		cnt++;
		cout<<cnt<<":"<<a<<"->"<<c<<endl;
	}else{
		hanoi(n-1,a,c,b);
		cnt++;
		cout<<cnt<<":"<<a<<"->"<<c<<endl;
		hanoi(n-1,b,a,c);
	}
}
void modi_hanoi(int n,char a,char b,char c){
	if(n==1){
		cnt++;
		if(cnt>=28){
			cout<<cnt-127+num<<":"<<a<<"->"<<c<<endl;
		}
	}
	else{
		modi_hanoi(n-1,a,c,b);
		cnt++;
		if(cnt>=28){
			cout<<cnt-127+num<<":"<<a<<"->"<<c<<endl;
		}
		modi_hanoi(n-1,b,a,c);
	}
}

int main()
{
	int n;
	while(cin>>n){
		num=pow((double)2,n)-1;
		cnt=0;
		cout<<num<<endl;
		if(n<=6)hanoi(n,'A','B','C');
		else if(n%2==1)modi_hanoi(7,'A','B','C');
		else modi_hanoi(7,'B','A','C');
	}
}

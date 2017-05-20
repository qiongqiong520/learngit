 ///
 /// @file    8267计算整数k.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-15 17:46:26
 ///
 
#include <iostream>
#include<string>
#include<list>
using std::cin;
using std::cout;
using std::endl;

void SetBit(int &n,int i,int v)
{
	if(v)
		n|=(1<<i);
	else
		n&=~(1<<i);
}
int GetBit(int n,int i)
{
	return (n>>i)&1;
}

int main()
{
	int n,i,j;
	int t;
	cin>>t;
	while(t--){
		cin>>n>>i>>j;
		int tmp =(0xffffffff<<i)&(0xffffffff >>(31-j));
		SetBit(tmp,i,GetBit(n,i));
		if(GetBit(n,j))
			SetBit(tmp,j,0);
		else
			SetBit(tmp,j,1);
		cout<<std::hex<<tmp<<endl;//cout<<hex表示后面的整数都以16进制输出.
	}
	return 0;
}

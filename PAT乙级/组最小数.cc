 ///
 /// @file    组最小数.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-31 15:51:40
 ///
 
#include <iostream>
#include<string>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(int argc,char* argv[])
{

	int amount[10]={0};
	string ret;
	for(int i=0;i<10;i++)
	{
		int temp;
		cin>>temp;
		amount[i]=temp;
	}
	int k=1;
	while(amount[k]==0)k++;
	ret.push_back(k+'0');
	for(int i=0;i<10;i++)
	{
		if(i==k){
			for(int j=1;j<amount[i];j++)
				ret.push_back(i+'0');
		}
		else{
			for(int j=0;j<amount[i];j++)
				ret.push_back(i+'0');
		}
	}
	cout<<ret<<endl;
	return 0;
}


 ///
 /// @file    旧键盘.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 14:11:48
 ///
 
#include <iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;
using std::string;
int main(int argc,char* argv[])
{
	string r,w;
	while(cin>>r>>w)
	{
		 char hash[256]={0};
		string ret;
		int j=0;
		for(int i=0;i<r.size();i++)
		{
		 	if(r[i]!=w[j]||j>=w.size())
			{
		 		if(r[i]>='a'&&r[i]<='z'){
		 			if(hash[r[i]-32]==0){
		 				hash[r[i]-32]=1;
						ret.push_back(r[i]-32);
					}
				}
				else if(hash[r[i]]==0){
					hash[r[i]]=1;
					ret.push_back(r[i]);
				}
			}
				else j++;
		}
		cout<<ret<<endl;
	}
	return 0;
}

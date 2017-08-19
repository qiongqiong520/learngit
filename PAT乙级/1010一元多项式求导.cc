 ///
 /// @file    1010一元多项式求导.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-01 17:54:32
 ///
 
#include <iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc,char* argv[])
{
	int temp;
	vector<int> fun;
	while(cin>>temp)
	{
		fun.push_back(temp);
	}
	for(int i=0;i<fun.size();i+=2){
		fun[i]*=fun[i+1];
		fun[i+1]--;
	}
	int k=fun.size();
	for(int i=0;i<fun.size();i++){
		if(i%2==0&&fun[i]==0){
			k=i;
			break;
		}
	}
	for(int i=0;i<k-1;i++)
		cout<<fun[i]<<' ';
	if(k!=0)cout<<fun[k-1]<<endl;
	else cout<<"0 0"<<endl;
	return 0;
}

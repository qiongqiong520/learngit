 ///
 /// @file    1001A+BforMatrices.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-05-18 21:35:19
 ///
 
#include <iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc,char* argv[])
{
	int m,n;
	while(cin>>m>>n){
		if(m==0)return 0;
		vector<vector<int> > m1(m,vector<int>(n,0));
		vector<vector<int> > m2(m,vector<int>(n,0));
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>m1[i][j];
			}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>m2[i][j];
	 	}
	}
	for(int i=0;i<m;i++){
		for(int  j=0;j<n;j++){
			m1[i][j]+=m2[i][j];
	 	}
	}
	int  count=0;
	for(int i=0;i<m;i++)
	{
		bool iszero=true;
		for(int j=0;j<n;j++){
			if(m1[i][j]!=0)
				iszero=false;
		}
	 	if(iszero)count++;
	}
	for(int i=0;i<n;i++)
	{
		bool iszero=true;
		for(int j=0;j<m;j++){
			if(m1[j][i]!=0)iszero=false;
		}
 		if(iszero)count++;
	}
	cout<<endl;
	cout<<count<<endl;
}

return 0;
}

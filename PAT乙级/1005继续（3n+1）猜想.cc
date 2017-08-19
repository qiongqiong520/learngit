 ///
 /// @file    1005继续（3n+1）猜想.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-03-30 15:45:01
 ///
 
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

int main(int argc,char *argv[]){
	int n;
	while(cin>>n)
	{
		unordered_set<int>s;
		vector<int> curr;
		int temp;
		for(int i=0;i<n;i++){
			cin>>temp;
			s.insert(temp);
			curr.push_back(temp);
		}
		for(int i=0;i<n;i++){
			int k=curr[i];//以ascii吗形式存储字符
			if(s.find(k)==s.end())continue;
			while(k>1){
				if(k%2==0)k/=2;
				else k=(k*3+1)/2;
				if(s.find(k)!=s.end()){
					s.erase(k);
				}
			}
		}
		vector<int> ret;
		while(!s.empty()){
			int k=*s.begin();
			ret.push_back(k);
			s.erase(k);
		}
		sort(ret.begin(),ret.end());
		for(int i=ret.size()-1;i>=1;i--){
			cout<<ret[i]<<" ";
		}
		cout<<ret[0]<<endl;
	}
	return 0;
}

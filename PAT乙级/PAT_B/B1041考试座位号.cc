 ///
 /// @file    B1041考试座位号.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-16 15:50:43
 ///
#include<unordered_map>
#include<utility>
#include<iostream>
#include<string>
using namespace std;
int main(int argc ,char* argv[]){
	int n;
	unordered_map<int,pair<string,int> >stu;
	while(cin>>n){
		for(int i=0;i<n;i++){
			string s;cin>>s;
			int a,b;cin>>a>>b;
			pair<string,int>curr;
			curr.first=s;curr.second=b;
			stu[a]=curr;
		}
		int m;cin>>m;
		for(int i=0;i<m;i++){
			int c;cin>>c;
			cout<<stu[c].first<<' '<<stu[c].second<<endl;
		}
	}
	return 0;
}

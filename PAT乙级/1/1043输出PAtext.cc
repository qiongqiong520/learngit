 ///
 /// @file    1043输出PAtext.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-07-04 23:21:01
 ///
 
#include <iostream>
#include<string>
#include<vector>
#include<utility>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::pair;

bool isempty(vector<pair<char,int> >a){
	for(int i=0;i<a.size();i++){
		if(a[i].second!=0)return false;
	}
	return true;
}
int main(int argc,char* argv[]){
	string s;
	while(cin>>s){
		pair<char,int> a;
		a.first='a';a.second=0;
		vector<pair<char,int> >count(6,a);
		string ret="PATtest";
		for(auto &a:s){
			if(a=='P'){count[0].first='P';count[0].second++;}
			if(a=='A'){count[1].first='A';count[1].second++;}
			if(a=='T'){count[2].first='T';count[2].second++;}
			if(a=='e'){count[3].first='e';count[3].second++;}
			if(a=='s'){count[4].first='s';count[4].second++;}
			if(a=='t'){count[5].first='t';count[5].second++;}
		}
		while(!isempty(count)){
			for(int i=0;i<count.size();i++){
				if(count[i].second!=0){
					cout<<count[i].first;
					count[i].second--;
				}
			}
		}
		cout<<endl;
	}
	return 0;
}

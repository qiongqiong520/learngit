 ///
 /// @file    1009说反话.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-06-01 17:45:44
 ///
 
#include<iostream>
#include<string>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
int main(int argc,char* argv[]){
	vector<string> s;
	string str;
	while(cin>>str)s.push_back(str);
	int n=s.size();
	for(int i=0;i<n/2;i++)
		s[i].swap(s[n-i-1]);
	for(int i=0;i<n-1;i++)
		cout<<s[i]<<' ';
	cout<<s[n-1]<<endl;
	return 0;
}

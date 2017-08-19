 ///
 /// @file    1038统计同成绩学生.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-04-04 20:40:02
 ///
 
#include <iostream>
using std::cin;
using std::string;
using std::cout;
using std::endl;

int main(){
	int n;
	while(cin>>n){
		int grade[101]={0};
		for(int i=0;i<n;i++){
			int a;cin>>a;
			grade[a]++;
		}
		int k;
		cin>>k;
		for(int i=0;i<k-1;i++){
			int a;
			cin>>a;
			cout<<grade[a]<<" ";
		}
		int a;
		cin>>a;
		cout<<grade[a]<<endl;
	}
	return 0;
}


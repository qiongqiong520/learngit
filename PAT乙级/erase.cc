 ///
 /// @file    erase.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 09:37:28
 ///
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=9;i++){
		vi.push_back(i);
	}
	vi.erase(vi.begin()+3);
	for(int i=0;i<vi.size();i++){
		printf("%d ",vi[i]);
	}
	return 0;
}

 ///
 /// @file    push_back.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2017-09-10 09:25:53
 ///
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	vector<int> vi;
	for(int i=1;i<=3;i++){
		vi.push_back(i);
	}
	for(int i=0;i<vi.size();i++){
		printf("%d ",vi[i]);
	}
	return 0;
}
